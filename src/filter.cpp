#include "filter.h"
#include <iostream>
#include <vector>

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
    std::cout << "  [LogTask] (placeholder)" << std::endl;
}