/*
 * File: window.cpp
 * File Created: Thursday, 18th March 2021 10:31:18 am
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 1:09:58 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

#include "include/mandelbrot.h"

#include <QPainter>
#include <QImage>

#include <iostream>

mandelbrot::mandelbrot(double min, double max) :
    min(min), max(max)
{}

img_bounds mandelbrot::get_bounds(int min, int max, int width, int height)
{
    if (width < height)
    {
        const double units_per_pixel = (max - min) / static_cast<double>(width);
        const double add_pad = (units_per_pixel * (height - width)) / 2.0;
        return {min, max, min - add_pad, max + add_pad};
    }
    else
    {
        const double units_per_pixel = (max - min) / static_cast<double>(height);
        const double add_pad = (units_per_pixel * (width - height)) / 2.0;
        return {min - add_pad, max + add_pad, min, max};
    }
}

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

void mandelbrot::paintEvent(QPaintEvent *event)
{
    constexpr int max_iter = 1000;

    QPainter painter(this);
    QImage img;

    img_bounds bounds = get_bounds(min, max, width(), height());

    for (int i = 0; i < height(); ++i)
    {
        double y_coord = static_cast<double>(i)/height() * (bounds.y_max - bounds.y_min) + bounds.y_min;
        for (int j = 0; j < width(); ++j)
        {
            double x_coord = static_cast<double>(j)/width() * (bounds.x_max - bounds.x_min) + bounds.x_min;
            int color_id = check({x_coord, y_coord}, max_iter);
            QPen pen;
            pen.setColor({std::min(color_id * 8, 255), 0, 0});
            if (color_id == max_iter)
            {
                pen.setColor({0,0,0});
            }
            painter.setPen(pen);
            painter.drawPoint(j, i);
        }
    }
}