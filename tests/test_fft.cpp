#include <gtest/gtest.h>
#include "fft.h"

TEST(FFTTest, RunsWithoutCrash) {
    EXPECT_NO_THROW(fftTask());
}