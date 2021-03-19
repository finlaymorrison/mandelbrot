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
#include <QMainWindow>

#include <complex>

struct ImgBounds
{
    double x_min, x_max;
    double y_min, y_max;
};

class Mandelbrot : public QWidget
{
    Q_OBJECT

private:
    ImgBounds true_img_bounds;
    ImgBounds disp_img_bounds;
    QPixmap image;
    int max_iterations;
    QMainWindow *parent;

    void update_image();
    static int check(std::complex<double> test_num, int iteration_limit);
    static ImgBounds get_bounds(double min, double max, double width, double height);
    void paint_mandelbrot();

public slots:
    void zoom_in_slot();
    void zoom_out_slot();

    void translate_xp_slot();
    void translate_xn_slot();
    void translate_yp_slot();
    void translate_yn_slot();

public:
    Mandelbrot(double min=-2, double max=2, int max_iterations=100, QMainWindow *parent=nullptr);

    void zoom_in(int num);
    void zoom_out(int num);

    void paintEvent(QPaintEvent *event) override;
};