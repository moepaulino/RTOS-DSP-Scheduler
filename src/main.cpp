#include "scheduler.h"
#include "filter.h"
#include "fft.h"
#include "logger.h"
#include <iostream>
#include <vector>
#include <filter.h>

int main() {
    Scheduler sched;

    std::vector<double> signal = {0,1,1,1,1,1,0,0,0,0};
    Filter filter;
    FFT fft;
    Logger logger("logs/system.log");

    auto filterTask = [&]() {
        double avg = filter.movingAverage(signal, 5);
        std::cout << "  [FilterTask] Avg = " << avg << "\n";
    };

    auto fftTask = [&]() {
        auto spectrum = fft.compute(signal);
        std::cout << "  [FFTTask] First bin magnitude = " << spectrum[0] << "\n";
    };

    auto loggerTask = [&]() {
        logger.log("System running. Signal size: " + std::to_string(signal.size()));
    };

    sched.addTask(filterTask, 2, 1);
    sched.addTask(fftTask, 3, 10);
    sched.addTask(loggerTask, 1, 5);

    sched.run(20);

    return 0;
}