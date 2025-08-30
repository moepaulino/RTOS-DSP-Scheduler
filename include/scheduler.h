#pragma once
#include <functional>
#include <vector>
#include <chrono>

struct Task {
    std::function<void()> func;
    int priority; // Higher number = runs first
    int period; // Period in ticks
    int nextRun;  // When this task should run next
};

class Scheduler {
public:
    Scheduler();
    void addTask(std::function<void()> func, int priority, int period);
    void run(int maxTicks);

private:
    std::vector<Task> tasks;
    int tick;
};