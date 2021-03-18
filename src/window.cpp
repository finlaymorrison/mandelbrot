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

#include "include/window.h"
#include "include/mandelbrot.h"

#include <QPainter>
#include <QImage>

#include <iostream>

window::window(double y_min, double y_max, double x_min, double x_max) :
    y_min(y_min), y_max(y_max), x_min(x_min), x_max(x_max)
{}

void window::paintEvent(QPaintEvent *event)
{
    constexpr int max_iter = 1000;

    QPainter painter(this);
    QImage img;

    for (int i = 0; i < height(); ++i)
    {
        double y_coord = static_cast<double>(i)/height() * (y_max - y_min) + y_min;
        for (int j = 0; j < width(); ++j)
        {
            double x_coord = static_cast<double>(j)/width() * (x_max - x_min) + x_min;
            int color_id = mandelbrot::check({x_coord, y_coord}, max_iter);
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