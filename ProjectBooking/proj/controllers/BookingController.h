#pragma once
#include <drogon/HttpController.h>
class BookingController : public drogon::HttpController<BookingController> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(BookingController::makeBooking, "/bookings", drogon::Post);
        ADD_METHOD_TO(BookingController::viewBooking, "/bookings/{1}", drogon::Get);
        ADD_METHOD_TO(BookingController::cancelBooking, "/bookings/{1}/cancel", drogon::Post);
    METHOD_LIST_END;

    void makeBooking(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    void viewBooking(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string bookingId);
    void cancelBooking(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback, std::string bookingId);
};
