#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

class Logger {
public:
    enum class Level {
        Info,
        Warning,
        Error,
        Debug
    };

    static Logger& getInstance();

    void setLogToFile(bool enable, const string& filename = "engine_log.txt");
    void log(const string& message, Level level = Level::Info);

private:
    Logger() = default;
    ~Logger();

    bool _logToFile = false;
    ofstream _file;

    string currentTimeString() const;
    string levelToString(Level level) const;
};
