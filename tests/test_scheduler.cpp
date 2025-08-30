#include "scheduler.h"
#include <gtest/gtest.h>
#include <vector>

TEST(SchedulerTest, RunsTasksByPriority) {
    Scheduler sched;
    std::vector<int> order;

    sched.addTask([&] { order.push_back(1); }, 1, 1);
    sched.addTask([&] { order.push_back(2); }, 5, 1); 

    sched.run(1); // one tick

    ASSERT_EQ(order.size(), 2);
    EXPECT_EQ(order[0], 2);
    EXPECT_EQ(order[1], 1);
}

TEST(SchedulerTest, RespectsPeriods) {
    Scheduler sched;
    std::vector<int> calls;

    sched.addTask([&] { calls.push_back(42); }, 1, 2);
    sched.run(5);
    EXPECT_EQ(calls.size(), 3);
}