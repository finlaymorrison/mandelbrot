/*
 * File: window.h
 * File Created: Thursday, 18th March 2021 10:31:13 am
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 1:10:18 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

#include <QWidget>
#include <QPaintEvent>

#include <complex>

struct img_bounds
{
    double x_min, x_max;
    double y_min, y_max;
};

class mandelbrot : public QWidget
{
    Q_OBJECT

private:
    double min, max;

    static int check(std::complex<double> test_num, int iteration_limit);
    static img_bounds get_bounds(int min, int max, int width, int height);

public:
    mandelbrot(double min=-2, double max=2);

    void paintEvent(QPaintEvent *event) override;

};