#include "server.h"
#include <fstream>
#include <iostream>
#include <csignal>

namespace {
    volatile std::sig_atomic_t g_shutdown = 0;
    void signalHandler(int sig) {
        g_shutdown = 1;
        drogon::app().quit(); // Останавливаем Drogon
    }
}

Server::Server() {
    loadConfig(); // Загружаем конфиг при создании сервера
}

void Server::loadConfig() {
    std::ifstream configFile("../config/config.json", std::ifstream::binary);
    if (!configFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть config.json" << std::endl;
        exit(1);
    }
    configFile >> config;
    configFile.close();
}

void Server::run() {
    // Настраиваем сервер по конфигу
    int port = config["server"]["port"].asInt();
    std::cout << "Сервер запущен на порту: " << port << std::endl;

    // Настраиваем Drogon
    drogon::app().addListener("0.0.0.0", port);
    drogon::app().run();
}
