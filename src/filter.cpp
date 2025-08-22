#include "filter.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>

std::string getTimestamp() {
    using namespace std::chrono;
    static auto start = steady_clock::now();  // program start reference
    auto now = steady_clock::now();
    auto ms = duration_cast<milliseconds>(now - start).count();

    std::ostringstream oss;
    oss << "[" << std::setw(2) << std::setfill('0') << (ms / 1000) / 60  // minutes
        << ":" << std::setw(2) << (ms / 1000) % 60                        // seconds
        << "." << std::setw(3) << ms % 1000 << "s]";                      // milliseconds
    return oss.str();
}

namespace fs = std::filesystem;

double movingAverage(const std::vector<double>& data, int windowSize) {
    
    if (data.size() < static_cast<size_t>(windowSize)) { return 0.0; };
    double sum = 0.0;
    
    for (size_t i = data.size() - windowSize; i < data.size(); i++) {
        sum += data[i];
    }
    return sum / windowSize;

}

static std::vector<double> signal;

void filterTask() {
    // Square wave
    signal.push_back((signal.size() % 20 < 10) ? 1.0 : 0.0); 
    double avg = movingAverage(signal, 5);
    std::cout << "  [FilterTask] Avg = " << avg << std::endl;
}

void logTask() {
    const std::string logDir = "logs";
    const std::string logFile = logDir + "/system.log";
    
    if (!fs::exists(logDir)) {
        fs::create_directory(logDir);
    }

    std::ofstream ofs(logFile, std::ios::app);
    if(!ofs) {
        std::cerr << " [LoggerTask] Error opening log file" << std::endl;
        return;
    }

    std::string msg = " [LoggerTask] " + getTimestamp() + " System running. Signal size: " + std::to_string(signal.size());

    // Write to the console
    std::cout << msg << std::endl;
    // Write to the log file
    ofs << msg << std::endl;

}