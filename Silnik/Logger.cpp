#include "Logger.h"
using namespace std;

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger::~Logger() {
    if (_file.is_open())
        _file.close();
}

void Logger::setLogToFile(bool enable, const string& filename) {
    _logToFile = enable;
    if (enable) {
        _file.open(filename, ios::out | ios::app);
        if (!_file.is_open()) {
            cerr << "[LOGGER ERROR] Nie można otworzyć pliku logu: " << filename << endl;
            _logToFile = false;
        }
    }
    else {
        _file.imbue(std::locale(".UTF-8"));
        if (_file.is_open())
            _file.close();
    }
}

string Logger::currentTimeString() const {
    time_t now = time(nullptr);
    char buf[32];
    tm timeInfo;
    localtime_s(&timeInfo, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeInfo);
    return buf;
}

string Logger::levelToString(Level level) const {
    switch (level) {
    case Level::Info:    return "INFO";
    case Level::Warning: return "WARNING";
    case Level::Error:   return "ERROR";
    case Level::Debug:   return "DEBUG";
    default:             return "UNKNOWN";
    }
}

void Logger::log(const string& message, Level level) {
    string fullMessage = "[" + currentTimeString() + "][" + levelToString(level) + "] " + message;

    // Wypisz na konsolę
    if (level == Level::Error)
        cerr << fullMessage << endl;
    else
        cout << fullMessage << endl;

    // Zapisz do pliku (jeśli włączono)
    if (_logToFile && _file.is_open()) {
        _file << fullMessage << endl;
    }
}
