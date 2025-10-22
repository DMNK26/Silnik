#include "Engine.h"
#include "Logger.h"

using namespace std;

// Główna funkcja programu
int main() {
	Logger::getInstance().setLogToFile(true, "engine_log.txt"); // Włącz logowanie do pliku
	Logger::getInstance().log("Uruchamianie gry...", Logger::Level::Info); // Logowanie informacji o uruchomieniu gry

    {
		Engine engine(600, 600, "TEST"); // Utworzenie instancji silnika graficznego
		engine.setClearColor(sf::Color(40, 60, 90)); // Ustawienie koloru czyszczenia ekranu
        engine.run();
    }

    Logger::getInstance().log("Gra zakończyła działanie.", Logger::Level::Info);
    return 0;
}
