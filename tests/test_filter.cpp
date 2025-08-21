#include <gtest/gtest.h>
#include "filter.h"

TEST(FilterTest, MovingAverageBasic) {
    std::vector<double> data = {1, 2, 3, 4, 5};
    EXPECT_DOUBLE_EQ(movingAverage(data, 5), 3.0);
    EXPECT_DOUBLE_EQ(movingAverage(data, 3), 4.0);
}

TEST(FilterTest, MovingAverageShortSignal) {
    std::vector<double> data = {1, 2};
    EXPECT_DOUBLE_EQ(movingAverage(data, 5), 0.0);
}