// include/logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
public:
    // Constructor opens logfile (creates logs/ dir if needed)
    explicit Logger(const std::string& filename);

    // Write a log entry to both logfile and console
    void log(const std::string& message);

private:
    std::ofstream logfile;
};

#endif // LOGGER_H