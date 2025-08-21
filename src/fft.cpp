#include "fft.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>

void fftTask() {
    const int N = 16;
    static std::vector<double> signal(N, 0.0);
    static int step = 0;

    // Sine wave
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2.0 * M_PI * i / N * step);
    }
    step++;

    // Allocate the FFT output
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    fftw_plan plan = fftw_plan_dft_r2c_1d(N, signal.data(), out, FFTW_ESTIMATE);

    fftw_execute(plan);

    double mag = sqrt(out[1][0]*out[1][0] + out[1][1]*out[1][1]);
    std::cout << "  [FFTTask] First bin magnitude = " << mag << std::endl;

    fftw_destroy_plan(plan);
    fftw_free(out);
}