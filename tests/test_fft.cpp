#include <gtest/gtest.h>
#include "fft.h"
#include <vector>

TEST(FFTTest, RunsWithoutCrash) {
    FFT fft;
    std::vector<double> data(16, 1.0);
    EXPECT_NO_THROW({
        auto spectrum = fft.compute(data);
    });
}