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

#include <QMainWindow>
#include <QPaintEvent>

class window : public QMainWindow
{
    Q_OBJECT

private:
    double y_min, y_max, x_min, x_max;

public:
    window(double y_min=-2, double y_max=2, double x_min=-2, double x_max=2);

    void paintEvent(QPaintEvent *event) override;

};