#pragma once
#include <string>

struct Booking {
    std::string bookingId;
    std::string flightNumber;
    std::string passengerName;
    std::string passportNumber;
    std::string bookingDate;
    std::string status;  // "confirmed" или "cancelled"
};
