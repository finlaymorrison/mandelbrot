/*
 * File: main.cpp
 * File Created: Thursday, 18th March 2021 10:11:27 am
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 1:09:42 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

#include <iostream>
#include <QApplication>

#include "include/window.h"
#include "include/mandelbrot.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    window win;
    win.resize(1000,1000);
    win.setWindowTitle("Mandelbrot");
    win.show();

    return app.exec();
}