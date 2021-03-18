/*
 * File: main-window.h
 * File Created: Thursday, 18th March 2021 3:50:28 pm
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 3:57:03 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

#include "mandelbrot.h"

#include <QMainWindow>
#include <QWheelEvent>
#include <QToolBar>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QToolBar *toolbar;

    Mandelbrot *mandelbrot;

public:
    MainWindow(int width=800, int height=800, QString title="Unnamed Window");

    void wheelEvent(QWheelEvent *event) override;
};