#include "include/mandelbrot.h"

#include <complex>
#include <iostream>

int mandelbrot::check(std::complex<double> test_num, int iteration_limit)
{
    std::complex<double> curr_num = test_num;
    int iterations = 0;
    while(std::abs(curr_num) < 4 && iterations < iteration_limit)
    {
        curr_num = curr_num * curr_num + test_num;
        ++iterations;
    }
    return iterations;
}