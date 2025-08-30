#include "scheduler.h"
#include "filter.h"
#include "fft.h"
#include <iostream>
#include <thread>
#include <chrono>

void runScheduler(int iter, int time) {
    for (int i = 0; i < iter; i++)
    {
        std::cout << "Iteration: " << i << std::endl;
        
        filterTask();

        if(i % 10 == 0) {
            fftTask();
            logTask();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(time));   
    }
}