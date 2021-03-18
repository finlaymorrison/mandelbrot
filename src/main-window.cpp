/*
 * File: main-window.cpp
 * File Created: Thursday, 18th March 2021 3:52:07 pm
 * Author: Finlay Morrison (morrison.fin02@gmail.com)
 * -----
 * Last Modified: Thursday, 18th March 2021 3:57:05 pm
 * Modified By: Finlay Morrison (morrison.fin02@gmail.com>)
 * -----
 * Copyright (CC BY-SA) - 2021 Finlay Morrison
 */

#include "include/main-window.h"

#include <QApplication>
#include <QPixmap>
#include <QAction>
#include <QIcon>

MainWindow::MainWindow(int width, int height, QString title)
{
    // Setting up window.
    resize(width,height);
    setWindowTitle(title);

    // Creating mandelbrot.
    mandelbrot = new Mandelbrot(-2, 2, 100, this);

    // Setting up GUI.
    toolbar = addToolBar("main toolbar");

    QPixmap zoom_in_pix("img/zoom-in.png");
    QAction *zoom_in_action = toolbar->addAction(QIcon(zoom_in_pix), "Zoom In");
    connect(zoom_in_action, &QAction::triggered, mandelbrot, &Mandelbrot::zoom_in_slot);

    QPixmap zoom_out_pix("img/zoom-out.png");
    QAction *zoom_out_action = toolbar->addAction(QIcon(zoom_out_pix), "Zoom Out");
    connect(zoom_out_action, &QAction::triggered, mandelbrot, &Mandelbrot::zoom_out_slot);

    toolbar->addSeparator();

    QPixmap quit_pix("img/quit.png");
    QAction *quit_action = toolbar->addAction(QIcon(quit_pix), "Quit");
    connect(quit_action, &QAction::triggered, qApp, &QApplication::quit);

    // Displaying mandelbrot.
    setCentralWidget(mandelbrot);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int clicks = event->delta() / 120;
    if (clicks > 0)
    {
        for (int i = 0; i < clicks; ++i)
        {
            mandelbrot->zoom_in_slot();
        }
    }
    else
    {
        for (int i = clicks; i < 0; ++i)
        {
            mandelbrot->zoom_out_slot();
        }
    }
}