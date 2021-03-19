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

    QPixmap translate_left_pix("img/left.png");
    QAction *translate_left_action = toolbar->addAction(QIcon(translate_left_pix), "Translate Left");
    translate_left_action->setShortcut(Qt::Key_A);
    connect(translate_left_action, &QAction::triggered, mandelbrot, &Mandelbrot::translate_xn_slot);

    QPixmap translate_up_pix("img/up.png");
    QAction *translate_up_action = toolbar->addAction(QIcon(translate_up_pix), "Translate Up");
    translate_up_action->setShortcut(Qt::Key_W);
    connect(translate_up_action, &QAction::triggered, mandelbrot, &Mandelbrot::translate_yn_slot);

    QPixmap translate_down_pix("img/down.png");
    QAction *translate_down_action = toolbar->addAction(QIcon(translate_down_pix), "Translate Down");
    translate_down_action->setShortcut(Qt::Key_S);
    connect(translate_down_action, &QAction::triggered, mandelbrot, &Mandelbrot::translate_yp_slot);

    QPixmap translate_right_pix("img/right.png");
    QAction *translate_right_action = toolbar->addAction(QIcon(translate_right_pix), "Translate Right");
    translate_right_action->setShortcut(Qt::Key_D);
    connect(translate_right_action, &QAction::triggered, mandelbrot, &Mandelbrot::translate_xp_slot);

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
        mandelbrot->zoom_in(clicks);
    }
    else
    {
        mandelbrot->zoom_out(-clicks);
    }
}