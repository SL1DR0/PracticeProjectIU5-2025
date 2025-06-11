#include "DataManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>

DataManager& DataManager::getInstance() {
    static DataManager instance;
    return instance;
}

std::string DataManager::getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buffer);
}

const std::vector<Booking>& DataManager::getBookings() const {
    return bookings;
}

const std::vector<Flight>& DataManager::getFlights() const {
    return flights;
}

const std::map<std::string, std::string>& DataManager::getUsers() const {
    return users;
}

DataManager::DataManager() {
    std::cout << "Initializing DataManager at " << getCurrentDateTime() << std::endl;
    loadFlights();
    // Загрузка пользователей из файла
    std::ifstream usersFile("../resources/users.txt");
    if (!usersFile.is_open()) {
        std::cout << "Warning: Could not open users.txt. Creating empty file at " << getCurrentDateTime() << std::endl;
        std::ofstream out("../resources/users.txt");
        if (!out.is_open()) {
            std::cout << "Error: Could not create users.txt at " << getCurrentDateTime() << std::endl;
            throw std::runtime_error("Failed to create users.txt");
        } else {
            out.close();
        }
    } else {
        std::string line;
        while (std::getline(usersFile, line)) {
            std::istringstream ss(line);
            std::string login, password;
            if (std::getline(ss, login, '|') && std::getline(ss, password)) {
                users[login] = password;
                std::cout << "Loaded user: " << login << " with password: " << password << " at " << getCurrentDateTime() << std::endl;
            }
        }
        usersFile.close();
    }

    // Загрузка бронирований из файла
    std::ifstream bookingsFile("../resources/bookings.txt");
    if (!bookingsFile.is_open()) {
        std::cout << "Warning: Could not open bookings.txt. Creating empty file at " << getCurrentDateTime() << std::endl;
        std::ofstream out("../resources/bookings.txt");
        if (!out.is_open()) {
            std::cout << "Error: Could not create bookings.txt at " << getCurrentDateTime() << std::endl;
            throw std::runtime_error("Failed to create bookings.txt");
        } else {
            out.close();
        }
    } else {
        std::string line;
        while (std::getline(bookingsFile, line)) {
            std::istringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;
            while (std::getline(ss, token, '|')) tokens.push_back(token);
            if (tokens.size() == 6) {
                Booking b = {tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]};
                bookings.push_back(b);
                std::cout << "Loaded booking: " << b.bookingId << " for flight: " << b.flightNumber << " at " << getCurrentDateTime() << std::endl;
                if (b.status == "confirmed") {
                    updateFlightSeats(b.flightNumber, -1);
                }
            }
        }
        bookingsFile.close();
    }
}

void DataManager::loadFlights() {
    flights = {
        {"SU-100", "Moscow", "New York", "2023-12-15", 5},
        {"SU-200", "London", "Paris", "2023-12-16", 3}
    };
    std::cout << "Flights loaded: " << flights.size() << " at " << getCurrentDateTime() << std::endl;
}

void DataManager::updateFlightSeats(const std::string& flightNumber, int delta) {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = std::find_if(flights.begin(), flights.end(),
                           [&flightNumber](const Flight& f) { return f.flightNumber == flightNumber; });
    if (it != flights.end() && it->availableSeats + delta >= 0) {
        it->availableSeats += delta;
        std::cout << "Updated seats for " << flightNumber << " to " << it->availableSeats << " at " << getCurrentDateTime() << std::endl;
    } else {
        std::cout << "Error: Could not update seats for " << flightNumber << " at " << getCurrentDateTime() << std::endl;
    }
}

void DataManager::addBooking(const Booking& booking) {
    std::lock_guard<std::mutex> lock(mutex);
    bookings.push_back(booking);
    if (booking.status == "confirmed") {
        updateFlightSeats(booking.flightNumber, -1);
    }
    std::ofstream out("../resources/bookings.txt", std::ios::app);
    if (!out.is_open()) {
        std::cout << "Error: Could not open bookings.txt for writing at " << getCurrentDateTime() << std::endl;
        throw std::runtime_error("Failed to open bookings.txt for writing");
    }
    std::cout << "Writing booking " << booking.bookingId << " to file at " << getCurrentDateTime() << std::endl;
    out << booking.bookingId << "|" << booking.flightNumber << "|" << booking.passengerName << "|"
        << booking.passportNumber << "|" << booking.bookingDate << "|" << booking.status << "\n";
    out.flush(); // Принудительная запись
    out.close();
    std::cout << "Added booking: " << booking.bookingId << " to file at " << getCurrentDateTime() << std::endl;
}

Booking* DataManager::findBooking(const std::string& bookingId) {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = std::find_if(bookings.begin(), bookings.end(),
                           [&bookingId](const Booking& b) { return b.bookingId == bookingId; });
    return (it != bookings.end()) ? &(*it) : nullptr;
}

void DataManager::updateBookingStatus(const std::string& bookingId, const std::string& status) {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = std::find_if(bookings.begin(), bookings.end(),
                           [&bookingId](const Booking& b) { return b.bookingId == bookingId; });
    if (it != bookings.end()) {
        if (it->status == "confirmed" && status == "cancelled") {
            updateFlightSeats(it->flightNumber, 1);
        }
        it->status = status;
        std::ofstream out("../resources/bookings.txt");
        if (!out.is_open()) {
            std::cout << "Error: Could not open bookings.txt for update at " << getCurrentDateTime() << std::endl;
            throw std::runtime_error("Failed to open bookings.txt for update");
        }
        for (const auto& b : bookings) {
            out << b.bookingId << "|" << b.flightNumber << "|" << b.passengerName << "|"
                << b.passportNumber << "|" << b.bookingDate << "|" << b.status << "\n";
        }
        out.flush();
        out.close();
        std::cout << "Updated status for booking: " << bookingId << " to " << status << " at " << getCurrentDateTime() << std::endl;
    } else {
        std::cout << "Error: Booking not found for update: " << bookingId << " at " << getCurrentDateTime() << std::endl;
    }
}

void DataManager::addUser(const std::string& login, const std::string& password) {
    std::lock_guard<std::mutex> lock(mutex);
    users[login] = password;
    std::ofstream out("../resources/users.txt", std::ios::app);
    if (!out.is_open()) {
        std::cout << "Error: Could not open users.txt for writing at " << getCurrentDateTime() << std::endl;
        throw std::runtime_error("Failed to open users.txt for writing");
    }
    out << login << "|" << password << "\n";
    out.close();
    std::cout << "Added user: " << login << " with password: " << password << " at " << getCurrentDateTime() << std::endl;
}

bool DataManager::checkUser(const std::string& login, const std::string& password) {
    std::lock_guard<std::mutex> lock(mutex);
    auto it = users.find(login);
    bool result = (it != users.end() && it->second == password);
    std::cout << "Checking user " << login << " with password " << password << ": " << (result ? "Success" : "Failure") << " at " << getCurrentDateTime() << std::endl;
    return result;
}
