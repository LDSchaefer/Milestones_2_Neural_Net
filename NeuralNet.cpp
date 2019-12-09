#include <iostream>
#include <vector>
#include "NeuralNet.h"


NeuralNet::NeuralNet(const std::vector<unsigned> &topology){
    unsigned long long num_layer = topology.size(); // Anzahl der Eingegebenen Werte für die Topologie (da frei wählbar)
    for(unsigned i = 0; i < num_layer ; i++){
        net_struct.push_back(Layer()); // Erstellt einen Layer(Vektor) in dem Objekt net_struct, welches ein Vektor von einem Vektor ist
        for(unsigned j = 0; j <= topology[i]; j++){ // Zugriff auf den eingegeben Wert um größe der Topologie abzufragen;
                                                    //<= um bias Neuron zu erstellen
            net_struct.back().push_back(Neuron());  // Mit .back greifen wir auf das zuletzt erstellte Element von net_struct zu
                                                    // .push_back speichert dann in dieser Position genau eine Instanz von Neuron ab
            std::cout << "Neuron erstellt"<<std::endl;
        }
    }
    int inp;
    std::cout << "Wollen sie alle Outputs des Neuralen Netzwerks ausgeben? ja=1, nein =0" <<std::endl;
    std::cin >> inp;
    std::vector<double> results;
    if(inp==1){
        output_all(results);
    }
    unsigned inp_val;
    char spec;
    std::vector<unsigned> val_list;
    std::cout << "Wollen sie spezielle Werte eingeben? 1 = ja"<<std::endl;
    std::cin >> spec;
    std::cout << "Geben sie einen Wert ein";
    std::cin >> inp_val;
    val_list.push_back(inp_val);
    while(spec==1){
        std::cout << "Wollen sie noch eine Wert eingeben? 1 = ja"<<std::endl;
        std::cin >> spec;
        std::cout << "Geben sie einen Wert ein";
        std::cin >> inp_val;
        val_list.push_back(inp_val);
    }
}

void NeuralNet::output_all(std::vector<double> &res_vals){ // Nimmt einen Vektor entgegen in dem die Resultate gespeichert werden sollen
    for(unsigned int i = 0;i < net_struct.back().size()-1;i++){ // wir gehen für jede Neurone des letzten Layers durch (Outputlayer)
        res_vals.push_back(net_struct.back()[i].softMax(net_struct.back()[i].val, i)); // wir pushen die Resultate jeweils in einen Vektor mit den Resulataten der Neuronen
    }
}

void NeuralNet::output_spec(){

}

void NeuralNet::read_in(){
    // Hier kommt Read In einer Datei hin siehe Milestone 1
    // Funktion soll sowohl Dateien als auch Batches eingelesen können -> überladen der Funktion für jeweils Batches und Dateien
}

void NeuralNet::backpropagation(){
    // Hier werden die erhaltenen Gewichtungen an die Neuronen/softmaxfunktion zurückgegeben
}

void NeuralNet::math_dist(){
    // Hier werden Winkel und Momentum für 4c berechnet (genaueres verständniss von softmax nötig)
}

// evtl. muss neuron_res in Neural Net berechnet werden
