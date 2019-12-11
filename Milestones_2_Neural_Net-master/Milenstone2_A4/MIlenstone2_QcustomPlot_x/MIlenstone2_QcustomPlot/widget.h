#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qcustomplot.h"
#include <QVBoxLayout>
#include <QPushButton> //QPushButton
#include <QVBoxLayout> //QVBoxLayout
#include "QComboBox"
#include <QSpinBox>
#include <QVector>
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //void coorSys();
    void test();
    //void addPoint(double x, double y);



private slots:
    void on_axWidget_customContextMenuRequested(const QPoint &pos);

    void on_comboBox_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Widget *ui;
    //window->
    QWidget *w;
    //Layout
    QVBoxLayout * layout = new QVBoxLayout;
    QCustomPlot coor;                //Erzeuge ein Koordinatensystem
    QCustomPlot * plotting = new QCustomPlot;
    QCustomPlot * customPlot;
};

#endif // WIDGET_H
