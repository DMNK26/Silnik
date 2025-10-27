#include "Engine.h"
#include "Logger.h"

using namespace std;


/**  Główna funkcja programu*/
int main() {
	Logger::getInstance().setLogToFile(true, "engine_log.txt"); /** [lab1.7] Włącz logowanie do pliku*/
	Logger::getInstance().log("Uruchamianie gry...", Logger::Level::Info); /** Logowanie informacji o uruchomieniu gry */

	{
		Engine engine(1200, 800, "TEST"); /**  Utworzenie instancji silnika graficznego*/
		engine.setClearColor(sf::Color(30, 30, 30)); /**  [lab1.6] Ustawienie koloru czyszczenia ekranu*/
		engine.run(); /** [lab1.4] Główna pętla gry */
	}

	Logger::getInstance().log("Gra zakonczyla dzialanie.", Logger::Level::Info);
	return 0;
}