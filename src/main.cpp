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