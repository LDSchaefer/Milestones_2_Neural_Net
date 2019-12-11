#include "widget.h"
#include "ui_widget.h"
#include "qcustomplot.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->w = ui->widget_3;


    //Widget::coorSys();

    //this->coor.setInteraction(QCP::iRangeDrag, true);
    //this->coor.addGraph();
    //this->coor.graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    //this->coor.graph(0)->setLineStyle(QCPGraph::lsNone);
    //connect(&this->coor, SIGNAL(mousePress(QMouseEvent*)), SLOT(clickedGraph(QMouseEvent*)));
    //this->coor.update();

}

Widget::~Widget()
{
    delete ui;
}

/*
void Widget::coorSys(){
    //Diese Funktion erzeugt eine graphische Darstellung eines Koordinatensystem, welche die Trainingsdaten
    //berechnet und die Schnittstellen ausgibt.

    QVector<double> x(101), y(101); //Hier werden die Koordinaten Variablen erzeugt.
    for(int i = 0; i < 101; i++){
        x[i] = i/50.0 - 1;          //Gehe von x-Achse -1 zu 1
        y[i] = x[i] * x[i];         //Hier wird die Quadratfunktion berechnet
    }
    //Erzeuge eine graphische Oberflaeche:
    this->coor.addGraph();
    this->coor.graph(0)->setData(x, y);
    this->coor.graph(0)->setPen(QPen(Qt::blue)); //Die Linie wird blau angezeigt.

    //Achsen des Koordinatensystem:
    coor.xAxis->setLabel("x-Achse");  //Die x-Achse wird beschriftet und angezeigt.
    coor.yAxis->setLabel("y-Achse");

    //Setze die Achsenbereiche, sodass man alle Daten sehen kann:
    this->coor.xAxis->setRange(-1, 1);         //x-Achse: von -1 bis 1
    this->coor.yAxis->setRange(0, 1);          //y-Achse: von 0 bis 1
    this->coor.replot();

    //Diese Funktion kann den Graphen ran zoomen:
    //this->coor.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);



    layout->addWidget(w);

    w->setLayout(layout);
    w->show();

}

void Widget::addPoint(double x, double y){

}
*/
void customePlot(){
    QVector<double> x(202), y(202);
    for(int i = 0; i < 202; i++){
        x[i] = i/100.0 - 1;
        y[i] = x[i] * x[i];
    }

    //plotting->addGraph();
    //plotting->graph(0)->setData(x, y);

    //plotting->xAxis->setLabel("X-Achse");
    //plotting->yAxis->setLabel("Y-Achse");

    //QMouseEvent * even = nullptr;
    //QPoint point = even->pos();
    //addPoint(plotting->xAxis->pixelToCoord(point.x(), plotting->yAxis->pixelToCoord(point.y())));

}

void Widget::test(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    this->customPlot->addGraph();
    this->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    this->customPlot->xAxis->setLabel("x");
    this->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    this->customPlot->xAxis->setRange(-1, 1);
    this->customPlot->yAxis->setRange(0, 1);
    this->customPlot->replot();

    this->layout->addWidget(w);
    this->w->setLayout(layout);
    this->w->show();
}

void lossRates()
{
    //Die Loss-Rates Funktion optimiert die Parameter von der Neural-Netzwerk
    //Dabei ist es eine Schätzungsfunktion, die bei anderen Funktion unterschiedlich sind
    //zwischen Schätzungswerte und wahre Werte.
    //Hier wird die Loss--Rates berechnet die aktuellen Werte des neuronalem Netzwerk.


}
