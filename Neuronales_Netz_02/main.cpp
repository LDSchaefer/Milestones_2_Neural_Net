/*
Erster Versuch ein Neurales Netzwerk aus mehreren Neuronen aus 1 zusammen zusetzen
*/
#include <iostream>
#include <vector>
#include "NeuralNet.h"


int main()
{
    std::vector<unsigned> topology;
    topology.push_back(1); //input für Topologie größe
    topology.push_back(2); //input für Topologie größe
    topology.push_back(3); //input für Topologie größe
    topology.push_back(4); //input für Topologie größe
    NeuralNet net(topology); //Verbindet die Topologie der Neuronen mit dem neuronalem Netzwerk

    return 0;
}

// Als Referenz: https://www.youtube.com/watch?v=KkwX7FkLfug
