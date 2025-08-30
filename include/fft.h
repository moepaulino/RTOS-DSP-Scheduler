#ifndef FFT_H
#define FFT_H

#include <vector>

class FFT {
    public:
        std::vector<double> compute(const std::vector<double>& data);
};

#endif