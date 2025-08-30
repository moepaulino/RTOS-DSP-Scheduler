#ifndef FILTER_H
#define FILTER_H

#include <vector>

class Filter {
    public:
        // Util for testing
        double movingAverage(const std::vector<double>& data, int windowSize);
};

// Tasks
void filterTask();
void logTask();

#endif