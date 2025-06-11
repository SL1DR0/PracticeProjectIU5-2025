#include "FlightController.h"
#include "DataManager.h"

void FlightController::getFlights(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
    Json::Value response(Json::arrayValue);
    auto flights = DataManager::getInstance().getFlights();
    for (const auto& flight : flights) {
        Json::Value f;
        f["flightNumber"] = flight.flightNumber;
        f["departure"] = flight.departure;
        f["destination"] = flight.destination;
        f["date"] = flight.date;
        f["availableSeats"] = flight.availableSeats;
        response.append(f);
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(response));
}
