#ifndef SERVER_H
#define SERVER_H

#include <drogon/drogon.h>
#include <jsoncpp/json/json.h>
class Server {
public:
    Server();
    void run();

private:
    void loadConfig();  // Метод для загрузки конфига
    Json::Value config; // Хранит настройки из файла
};

#endif // SERVER_H
