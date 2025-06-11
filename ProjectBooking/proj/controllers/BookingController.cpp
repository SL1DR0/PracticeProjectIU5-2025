#include "BookingController.h"
#include "DataManager.h"
#include <ctime>
#include <iostream>

std::string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buffer);
}

void BookingController::makeBooking(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    std::cout << "Processing booking request at " << getCurrentDateTime() << " (session check disabled)" << std::endl;
    auto json = req->getJsonObject();
    if (!json) {
        std::cout << "Error: No JSON data in booking request at " << getCurrentDateTime() << std::endl;
        callback(drogon::HttpResponse::newHttpJsonResponse(Json::Value("Invalid input")));
        return;
    }
    if (!json->isMember("flightNumber") || !json->isMember("passengerName") || !json->isMember("passportNumber")) {
        std::cout << "Error: Missing required fields in booking request at " << getCurrentDateTime() << std::endl;
        callback(drogon::HttpResponse::newHttpJsonResponse(Json::Value("Invalid input")));
        return;
    }

    std::string flightNumber = (*json)["flightNumber"].asString();
    std::string passengerName = (*json)["passengerName"].asString();
    std::string passportNumber = (*json)["passportNumber"].asString();
    std::string bookingId = flightNumber + "-" + passportNumber.substr(std::max(0, (int)passportNumber.length() - 4));
    std::string bookingDate = getCurrentDateTime();

    auto& dataManager = DataManager::getInstance();
    const auto& bookings = dataManager.getBookings();
    std::cout << "Checking " << bookings.size() << " existing bookings at " << getCurrentDateTime() << std::endl;
    for (size_t i = 0; i < bookings.size() && i < 1000; ++i) {
        const auto& booking = bookings[i];
        if (booking.passportNumber == passportNumber && booking.flightNumber == flightNumber && booking.status == "confirmed") {
            std::cout << "Booking already exists for " << bookingId << " at " << getCurrentDateTime() << std::endl;
            callback(drogon::HttpResponse::newHttpJsonResponse(Json::Value("Booking already exists")));
            return;
        }
    }

    Booking newBooking = {bookingId, flightNumber, passengerName, passportNumber, bookingDate, "confirmed"};
    std::cout << "Attempting to add booking " << bookingId << " at " << getCurrentDateTime() << std::endl;
    try {
        dataManager.addBooking(newBooking);
        std::cout << "Booking created: " << bookingId << " at " << getCurrentDateTime() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error adding booking " << bookingId << ": " << e.what() << " at " << getCurrentDateTime() << std::endl;
        callback(drogon::HttpResponse::newHttpJsonResponse(Json::Value("Internal server error")));
        return;
    }

    Json::Value resp;
    resp["message"] = "Booking created";
    resp["bookingId"] = bookingId;
    auto response = drogon::HttpResponse::newHttpJsonResponse(resp);
    std::cout << "Response object created, status: " << (response ? "valid" : "null") << " at " << getCurrentDateTime() << std::endl;
    std::cout << "Sending callback with response at " << getCurrentDateTime() << std::endl;
    callback(response);
}

void BookingController::viewBooking(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string bookingId) {
    std::cout << "Processing viewBooking request at " << getCurrentDateTime() << " (session check disabled)" << std::endl;
    auto booking = DataManager::getInstance().findBooking(bookingId);
    if (booking) {
        std::cout << "Viewing booking: " << bookingId << " at " << getCurrentDateTime() << std::endl;
        Json::Value resp;
        resp["bookingId"] = booking->bookingId;
        resp["flightNumber"] = booking->flightNumber;
        resp["passengerName"] = booking->passengerName;
        resp["passportNumber"] = booking->passportNumber;
        resp["bookingDate"] = booking->bookingDate;
        resp["status"] = booking->status;
        callback(drogon::HttpResponse::newHttpJsonResponse(resp));
    } else {
        std::cout << "Booking not found: " << bookingId << " at " << getCurrentDateTime() << std::endl;
        callback(drogon::HttpResponse::newHttpJsonResponse(Json::Value("Booking not found")));
    }
}

void BookingController::cancelBooking(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string bookingId) {
    std::cout << "Processing cancelBooking request at " << getCurrentDateTime() << " (session check disabled)" << std::endl;
    try {
        DataManager::getInstance().updateBookingStatus(bookingId, "cancelled");
        std::cout << "Booking cancelled: " << bookingId << " at " << getCurrentDateTime() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error cancelling booking " << bookingId << ": " << e.what() << " at " << getCurrentDateTime() << std::endl;
        callback(drogon::HttpResponse::newHttpJsonResponse(Json::Value("Internal server error")));
        return;
    }
    Json::Value resp;
    resp["message"] = "Booking cancelled";
    callback(drogon::HttpResponse::newHttpJsonResponse(resp));
}
