#ifndef NEURON_H
#define NEURON_H

#endif // NEURON_H

#include <vector>
#include <iostream>

class Neuron;

typedef std::vector<Neuron> Layer; // Erstellt einen Vektor Namens Layer in dem  die Vektoren der Neuron Klasse ablegt werden
                                   // Muss evtl. ebenfalls in .h ausgelagert werden
class Neuron{ // Dummy Klasse
public:
    static double rand_wights(void)
    {
        return rand() / double(RAND_MAX); //Zufällige Zahlen von 0 bis 1
    }

    ///Hier werden die weights definiert die man für die Neuronenverbindung rein zufällig mit berechnet werden
    struct Connection{
        double weight;
        double delta;
    };

    std::vector<unsigned int> val ;
    Neuron(); ///Anzahl der Outputs
    ///unsigned out_Num
    double sigma; //transfer function from the inputs
    //sum of the vector
    double sum;
    float softMax(std::vector<unsigned> input_val, int pos);
    float sum_ex();
    double weight = rand() / double(RAND_MAX); ///Weight Randomzahlen von 0 bis 1

    //std::vector<Connection> weights_out; ///Die Gewichtung werden in der Neuron zusätzlich verwendet

    ///d)
    /// Funktion, mit der zum einen die Output-Gradienten
    /// für Output-LayerNeuronen, zum anderen die Hidden-Gradienten
    /// für alle Hidden-Layer berechnet werden können
    float outputGradient(const Layer &nextLayer);
    float sumHid(const Layer &nextLayer);


};
