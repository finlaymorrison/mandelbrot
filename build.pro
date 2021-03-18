TEMPLATE = app
TARGET = mandelbrot
INCLUDEPATH += .

SOURCES +=  src/*.cpp

HEADERS +=  src/include/*.h

CONFIG += CONSOLE silent release

QT += core gui widgets