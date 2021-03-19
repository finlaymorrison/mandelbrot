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
#include <QPalette>

Mandelbrot::Mandelbrot(double min, double max, int max_iterations, QMainWindow *parent) :
    true_img_bounds(), disp_img_bounds(), image(height(), width()), max_iterations(max_iterations),  parent(parent)
{
    if (width() < height())
    {
        const double units_per_pixel = (max - min) / static_cast<double>(width());
        const double add_pad = (units_per_pixel * (height() - width())) / 2.0;
        true_img_bounds = ImgBounds{min, max, min - add_pad, max + add_pad};
    }
    else
    {
        const double units_per_pixel = (max - min) / static_cast<double>(height());
        const double add_pad = (units_per_pixel * (width() - height())) / 2.0;
        true_img_bounds = ImgBounds{min - add_pad, max + add_pad, min, max};
    }
    disp_img_bounds = true_img_bounds;
    
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);

    update_image();
}

int Mandelbrot::check(std::complex<double> test_num, int iteration_limit)
{
    std::complex<double> curr_num = test_num;
    int iterations = 0;
    while(curr_num.real() * curr_num.real() + curr_num.imag() * curr_num.imag() < 4 && iterations < iteration_limit)
    {
        curr_num = curr_num * curr_num + test_num;
        ++iterations;
    }
    return iterations;
}

void Mandelbrot::update_image()
{
    ImgBounds target_bounds = disp_img_bounds;

    QPixmap buffer(width(), height());
    QPainter buffer_painter(&buffer);

    for (int i = 0; i < height(); ++i)
    {
        double y_coord = static_cast<double>(i)/height() * (target_bounds.y_max - target_bounds.y_min) + target_bounds.y_min;
        for (int j = 0; j < width(); ++j)
        {
            double x_coord = static_cast<double>(j)/width() * (target_bounds.x_max - target_bounds.x_min) + target_bounds.x_min;
            int color_id = check({x_coord, y_coord}, max_iterations);
            QPen pen;
            pen.setColor({std::min(color_id * 5, 255), 0, 0});
            if (color_id == max_iterations)
            {
                pen.setColor({0,0,0});
            }
            buffer_painter.setPen(pen);
            buffer_painter.drawPoint(j, i);
        }
    }

    true_img_bounds = target_bounds;
    image = buffer;
}

void Mandelbrot::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    paint_mandelbrot();
}

void Mandelbrot::paint_mandelbrot()
{
    double real_img_w = true_img_bounds.x_max - true_img_bounds.x_min;
    double real_img_h = true_img_bounds.y_max - true_img_bounds.y_min;

    double disp_img_w = disp_img_bounds.x_max - disp_img_bounds.x_min;
    double disp_img_h = disp_img_bounds.y_max - disp_img_bounds.y_min;

    double proj_img_w = real_img_w / disp_img_w;
    double proj_img_h = real_img_h / disp_img_h;

    double proj_img_offeset_w = true_img_bounds.x_min - disp_img_bounds.x_min;
    double proj_img_offeset_h = disp_img_bounds.y_max - true_img_bounds.y_max;

    double pixels_per_unit_w = width() / disp_img_w;
    double pixels_per_unit_h = height() / disp_img_h;

    QPainter painter(this);

    painter.drawPixmap(proj_img_offeset_w * pixels_per_unit_w, proj_img_offeset_h * pixels_per_unit_h, proj_img_w * width(), proj_img_h * height(), image);
}

void Mandelbrot::zoom_in_slot()
{   
    zoom_in(1);
}

void Mandelbrot::zoom_out_slot()
{
    zoom_out(1);
}

void Mandelbrot::zoom_in(int num)
{
    constexpr double zoom_amount = 1.0 / 1.1;

    while(num--)
    {
        disp_img_bounds.y_max *= zoom_amount;
        disp_img_bounds.y_min *= zoom_amount;
        disp_img_bounds.x_max *= zoom_amount;
        disp_img_bounds.x_min *= zoom_amount;
    }

    repaint();

    update_image();

    repaint();
}

void Mandelbrot::zoom_out(int num)
{
    constexpr double zoom_amount = 1.1;

    while(num--)
    {
        disp_img_bounds.y_max *= zoom_amount;
        disp_img_bounds.y_min *= zoom_amount;
        disp_img_bounds.x_max *= zoom_amount;
        disp_img_bounds.x_min *= zoom_amount;
    }

    repaint();

    update_image();

    repaint();
}