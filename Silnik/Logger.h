#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

/// Klasa Loggera do logowania informacji do konsoli i opcjonalnie do pliku 
class Logger {
public:
    /// Klasa zawierająca typy błędów pod odpowiednio przypisanymi numerami, dzięki enum
    enum class Level {
        Info,
        Warning,
        Error,
        Debug
    };

    static Logger& getInstance();
    /// Ustawia czy zapisywać logi do pliku
    void setLogToFile(bool enable, const string& filename = "engine_log.txt");
    /// Log, czyli informacja o aktualznym działaniu. Zawiera wiadomość oraz typ błędu z klasy Level
    void log(const string& message, Level level = Level::Info);
    
	
private:
    /// Usunięcie kopiowania i przypisania
    Logger() = default;
    /// Destruktor
    ~Logger();

    bool _logToFile = false;
    ofstream _file;
    /// Aktualny czas w ciągu znaków
    string currentTimeString() const;
    /// Zamienia numer typu błędu na jego słowny odpowiednik
    string levelToString(Level level) const;
};
