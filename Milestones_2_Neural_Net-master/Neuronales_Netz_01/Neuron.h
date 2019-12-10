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
    std::vector<unsigned int> val ;
    Neuron();
    double sigma; //tranfer function from the inputs
    //sum of the vector
    double sum;
    float softMax(std::vector<unsigned> input_val, int pos);
    float sum_ex();
};
