#ifndef NEUROALNET_H
#define NEUROALNET_H

#endif // NEURALNET_H

#include <vector>
#include <iostream>
#include "Neuron.h"

class NeuralNet:Neuron{ // Neuron muss evtl. nicht vererbt werden
public:
    // 2a
    NeuralNet(const std::vector<unsigned> &topology);
    // 2b
    void output_all(std::vector<double> &res_vals);
    // 2c
    void output_spec();
    // 2d
    void read_in();
    // 2e
    void backpropagation();
    // 2f
    void math_dist();
private:
    std::vector<Layer> net_struct; // Die Strucktur unseres Netzes,
                                   //Zugriff auf einzelne Neuronen/Vektoren: net_struct[layer_num][neuron_num]

};
