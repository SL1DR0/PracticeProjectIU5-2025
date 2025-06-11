#pragma once
#include <drogon/HttpController.h>
class FlightController : public drogon::HttpController<FlightController> {
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(FlightController::getFlights, "/flights", drogon::Get);
    METHOD_LIST_END;

    void getFlights(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
};
