#include "widget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton> //QPushButton
#include <QVBoxLayout> //QVBoxLayout
#include "QComboBox"
#include <QSpinBox>
#include "qcustomplot.h" //QCustomPlot
#include <QVector>
#include <QPen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
