#include "logger.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>

Logger::Logger(const std::string& filename) {
    std::filesystem::create_directories("logs");
    logfile.open("logs/" + filename, std::ios::out | std::ios::app);
}

void Logger::log(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  now.time_since_epoch()
              ).count();

    if (logfile.is_open()) {
        logfile << "[LoggerTask] [" << ms << "ms] " << message << std::endl;
    }
    std::cout << "[LoggerTask] [" << ms << "ms] " << message << std::endl;
}