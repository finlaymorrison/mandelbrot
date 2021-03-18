/*
 * File: mandelbrot.cpp
 * File Created: Thursday, 18th March 2021 10:47:22 am
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 1:09:49 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

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