#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

/// Klasa Loggera do logowania informacji do konsoli i opcjonalnie do pliku 
class Logger {
public:
    /// komentarz
    enum class Level {
        Info,
        Warning,
        Error,
        Debug
    };

    static Logger& getInstance();
    /// komentarz
    void setLogToFile(bool enable, const string& filename = "engine_log.txt");
    /// komentarz
    void log(const string& message, Level level = Level::Info);
    
	
private:
    /// Usunięcie kopiowania i przypisania
    Logger() = default;
    /// komentarz
    ~Logger();

    bool _logToFile = false;
    ofstream _file;
    /// komentarz
    string currentTimeString() const;
    /// komentarz
    string levelToString(Level level) const;
};
