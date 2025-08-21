#ifndef FILTER_H
#define FILTER_H

#include <vector>

// Tasks
void filterTask();
void logTask();

// Util for testing
double movingAverage(const std::vector<double>& data, int windowSize);

#endif