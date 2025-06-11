#include <drogon/drogon.h>
#include <iostream>

int main() {
    std::cout << "Starting app at " << std::time(nullptr) << " CEST" << std::endl;
    try {
        drogon::app().loadConfigFile("config.json");
        std::cout << "Configuration loaded successfully" << std::endl;
        #ifdef DROGON_VERSION
            std::cout << "Drogon version: " << DROGON_VERSION << std::endl;
        #else
            std::cout << "Drogon version: Unknown. Checking runtime version..." << std::endl;
            std::cout << "Runtime version: " << drogon::getVersion() << std::endl;
        #endif
        drogon::app().run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
