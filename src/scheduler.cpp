#include "scheduler.h"
#include <algorithm>
#include <iostream>

Scheduler::Scheduler() : tick(0) {}

void Scheduler::addTask(std::function<void()> func, int priority, int period) {
    tasks.push_back({func, priority, period, 0});
}

void Scheduler::run(int maxTicks) {
    for (tick = 0; tick < maxTicks; ++tick) {
        std::cout << "Tick: " << tick << "\n";

        // Find all tasks ready to run
        std::vector<Task*> ready;
        for (auto &t : tasks) {
            if (tick >= t.nextRun) {
                ready.push_back(&t);
            }
        }

        // Sort ready tasks by priority
        std::sort(ready.begin(), ready.end(),
                  [](Task* a, Task* b) { return a->priority > b->priority; });

        for (auto *t : ready) {
            t->func();
            t->nextRun = tick + t->period;
        }
    }
}