#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>
#include <map>
#include <mutex>

struct Flight {
    std::string flightNumber;
    std::string departure;
    std::string destination;
    std::string date;
    int availableSeats;
};

struct Booking {
    std::string bookingId;
    std::string flightNumber;
    std::string passengerName;
    std::string passportNumber;
    std::string bookingDate;
    std::string status;
};

class DataManager {
public:
    static DataManager& getInstance(); // Статический метод для синглтона
    DataManager(const DataManager&) = delete; // Запрет копирования
    DataManager& operator=(const DataManager&) = delete; // Запрет присваивания
    ~DataManager() = default;

    void loadFlights();
    void updateFlightSeats(const std::string& flightNumber, int delta);
    void addBooking(const Booking& booking);
    Booking* findBooking(const std::string& bookingId);
    void updateBookingStatus(const std::string& bookingId, const std::string& status);
    void addUser(const std::string& login, const std::string& password);
    bool checkUser(const std::string& login, const std::string& password);
    const std::vector<Booking>& getBookings() const; // Метод для доступа к бронированиям
    const std::vector<Flight>& getFlights() const;   // Метод для доступа к рейсам
    const std::map<std::string, std::string>& getUsers() const; // Новый метод для доступа к пользователям

    static std::string getCurrentDateTime();

private:
    DataManager(); // Приватный конструктор для синглтона
    std::vector<Flight> flights;
    std::vector<Booking> bookings;
    std::map<std::string, std::string> users;
    std::mutex mutex;
};

#endif
