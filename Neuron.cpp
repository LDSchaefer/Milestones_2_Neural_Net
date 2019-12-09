#include <iostream>
#include <vector>
#include <math.h>
#include "Neuron.h"

Neuron::Neuron(){
    for(unsigned int i=0;i<3;i++)
    {
        val.push_back(i);
    }
    softMax(val, 0);
}

float Neuron::sum_ex(){
    float sum = 0;
    return sum;
}

float Neuron::softMax(std::vector<unsigned> input_val, int pos){
    float sum = 0;
    for(unsigned int i = 0; i < input_val.size(); i++) // für jeden wert des eingegebenen vektors wird der e hoch i berechnet
    {
        float ex = std::exp(input_val.at(i));
        sum = sum + ex; // alle Werte werden in sum addiert
    }
    float sigma = std::exp(input_val.at(pos))/sum; // Der Wert an der gegebenen Position (i auf Blatt) wird durch sum geteilt
    std::cout << "" << sigma << "\n";
    return sigma; // der erhaltene Wert wird zurückgegeben
}


