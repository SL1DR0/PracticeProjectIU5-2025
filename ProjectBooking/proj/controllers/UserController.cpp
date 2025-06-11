#include "UserController.h"
#include "DataManager.h"
#include <iostream>

void UserController::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto json = req->getJsonObject();
    if (!json) {
        std::cout << "Error: No JSON data in register request" << std::endl;
        callback(HttpResponse::newHttpJsonResponse(Json::Value("Invalid data")));
        return;
    }
    if (!json->isMember("login") || !json->isMember("password")) {
        std::cout << "Error: Missing login or password in register request" << std::endl;
        callback(HttpResponse::newHttpJsonResponse(Json::Value("Invalid data")));
        return;
    }

    std::string login = (*json)["login"].asString();
    std::string password = (*json)["password"].asString();

    if (DataManager::getInstance().getUsers().count(login)) {
        std::cout << "User already exists: " << login << std::endl;
        callback(HttpResponse::newHttpJsonResponse(Json::Value("User already exists")));
        return;
    }

    DataManager::getInstance().addUser(login, password);
    std::cout << "User registered: " << login << std::endl;
    Json::Value resp;
    resp["message"] = "Registration successful";
    auto response = HttpResponse::newHttpJsonResponse(resp);
    std::cout << "Response object created, status: " << (response ? "valid" : "null") << std::endl;
    std::cout << "Sending callback with response" << std::endl;
    callback(response);
}

void UserController::loginUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
    auto json = req->getJsonObject();
    if (!json) {
        std::cout << "Error: No JSON data in login request" << std::endl;
        callback(HttpResponse::newHttpJsonResponse(Json::Value("Invalid data")));
        return;
    }
    if (!json->isMember("login") || !json->isMember("password")) {
        std::cout << "Error: Missing login or password in login request" << std::endl;
        callback(HttpResponse::newHttpJsonResponse(Json::Value("Invalid data")));
        return;
    }

    std::string login = (*json)["login"].asString();
    std::string password = (*json)["password"].asString();

    if (DataManager::getInstance().checkUser(login, password)) {
        std::cout << "Login successful for: " << login << std::endl;
        if (!req->session()) {
            std::cout << "Error: Session not available" << std::endl;
            auto resp = HttpResponse::newHttpJsonResponse(Json::Value("Session error"));
            resp->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);
            callback(resp);
            return;
        }
        std::cout << "Session available, inserting loggedInUser" << std::endl;
        req->session()->insert("loggedInUser", login);
        std::cout << "Session updated with loggedInUser" << std::endl;
        Json::Value resp;
        resp["message"] = "Login successful";
        auto response = HttpResponse::newHttpJsonResponse(resp);
        std::cout << "Response object created, status: " << (response ? "valid" : "null") << std::endl;
        std::cout << "Sending callback with response" << std::endl;
        callback(response);
    } else {
        std::cout << "Login failed for: " << login << std::endl;
        callback(HttpResponse::newHttpJsonResponse(Json::Value("Invalid credentials")));
    }
}
