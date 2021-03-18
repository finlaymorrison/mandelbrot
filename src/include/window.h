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