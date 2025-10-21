#include "Engine.h"
#include "Logger.h"
using namespace std;

int main() {
    Logger::getInstance().setLogToFile(true, "engine_log.txt");
    Logger::getInstance().log("Uruchamianie gry...", Logger::Level::Info);

    {
        Engine engine(600, 600, "TEST");
        engine.setClearColor(sf::Color(40, 60, 90));
        engine.run();
    }

    Logger::getInstance().log("Gra zakończyła działanie.", Logger::Level::Info);
    return 0;
}
