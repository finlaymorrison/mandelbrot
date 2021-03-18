/*
 * File: mandelbrot.h
 * File Created: Thursday, 18th March 2021 10:43:17 am
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 1:10:07 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

#include <complex>

class mandelbrot
{
public:
    static int check(std::complex<double> test_num, int iteration_limit);
};