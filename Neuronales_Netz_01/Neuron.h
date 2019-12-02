#ifndef NEURON_H
#define NEURON_H

#endif // NEURON_H

#include <vector>
#include <iostream>

class Neuron{ // Dummy Klasse
public:
    double sigma; //tranfer function from the inputs
    //sum of the vector
    double sum;
    void softMax();
    int neuron_res();
    float sum_ex();
};

typedef std::vector<Neuron> Layer; // Erstellt einen Vektor Namens Layer in dem  die Vektoren der Neuron Klasse ablegt werden
                                   // Muss evtl. ebenfalls in .h ausgelagert werden

