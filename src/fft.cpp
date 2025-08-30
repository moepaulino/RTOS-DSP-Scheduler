#include "fft.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>

std::vector<double> FFT::compute(const std::vector<double>& data) {
    const int N = data.size();
    std::vector<double> magnitudes;

    // Allocate the FFT output
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_plan plan = fftw_plan_dft_r2c_1d(N, const_cast<double*>(data.data()), out, FFTW_ESTIMATE);

    fftw_execute(plan);

    // Compute magnitudes
    int bins = N / 2 + 1;
    magnitudes.resize(bins);
    for (int i = 0; i < bins; i++) {
        magnitudes[i] = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
    }

    fftw_destroy_plan(plan);
    fftw_free(out);

    return magnitudes;
}