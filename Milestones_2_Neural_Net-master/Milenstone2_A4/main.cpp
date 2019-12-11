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


class Graphic{
private:
    //window->
    QWidget * w = plotwidget;
    //Layout
    QVBoxLayout * layout = new QVBoxLayout;
    QCustomPlot coor;                //Erzeuge ein Koordinatensystem
    QCustomPlot * plotting = new QCustomPlot;


public:

    void coorSys(){
        //Diese Funktion erzeugt eine graphische Darstellung eines Koordinatensystem, welche die Trainingsdaten
        //berechnet und die Schnittstellen ausgibt.

        QVector<double> x(101), y(101); //Hier werden die Koordinaten Variablen erzeugt.
        for(int i = 0; i < 101; i++){
            x[i] = i/50.0 - 1;          //Gehe von x-Achse -1 zu 1
            y[i] = x[i] * x[i];         //Hier wird die Quadratfunktion berechnet
        }
        //Erzeuge eine graphische Oberflaeche:
        coor.addGraph();
        coor.graph(0)->setData(x, y);
        coor.graph(0)->setPen(QPen(Qt::blue)); //Die Linie wird blau angezeigt.

        //Achsen des Koordinatensystem:
        coor.xAxis->setLabel("x-Achse");  //Die x-Achse wird beschriftet und angezeigt.
        coor.yAxis->setLabel("y-Achse");

        //Setze die Achsenbereiche, sodass man alle Daten sehen kann:
        coor.xAxis->setRange(-1, 1);         //x-Achse: von -1 bis 1
        coor.yAxis->setRange(0, 1);          //y-Achse: von 0 bis 1
        coor.replot();

        //Diese Funktion kann den Graphen ran zoomen:
        coor.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);



        layout->addWidget(coor);
        w->setLayout(layout);
        w->show();

    }

    void lossRates(){
        //Die Loss-Rates Funktion optimiert die Parameter von der Neural-Netzwerk
        //Dabei ist es eine Schätzungsfunktion, die bei anderen Funktion unterschiedlich sind
        //zwischen Schätzungswerte und wahre Werte.
        //Hier wird die Loss--Rates berechnet die aktuellen Werte des neuronalem Netzwerk.



    }

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Graphic graf;
    graf.coorSys();

    return a.exec();
}
