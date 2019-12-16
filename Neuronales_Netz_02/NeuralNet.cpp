#include <iostream>
#include <vector>
#include <fstream>
#include "NeuralNet.h"
#include <string>


NeuralNet::NeuralNet(const std::vector<unsigned> &topology){

    unsigned long long num_layer = topology.size(); // Anzahl der Eingegebenen Werte für die Topologie (da frei wählbar)

    for(unsigned i = 0; i < num_layer ; i++){
        net_struct.push_back(Layer()); // Erstellt einen Layer(Vektor) in dem Objekt net_struct, welches ein Vektor von einem Vektor ist

        for(unsigned j = 0; j <= topology[i]; j++){ // Zugriff auf den eingegeben Wert um größe der Topologie abzufragen;
                                                    //<= um bias Neuron zu erstellen
            ///Wenn der Output Layer Anzahl des höchsten Output Layer ist
            ///unsigned out_Num = num_layer == topology.size() - 1 ?  0 : topology[num_layer + 1];
            ///out_Num
            net_struct.back().push_back(Neuron());  // Mit .back greifen wir auf das zuletzt erstellte Element von net_struct zu
                                                    // .push_back speichert dann in dieser Position genau eine Instanz von Neuron ab
            std::cout << " Neuron erstellt "<<std::endl;
        }
    }

    int inp;
    std::cout << "Wollen sie alle Outputs des Neuralen Netzwerks ausgeben? ja = 1, nein = 0" << std::endl;
    std::cin >> inp;
    std::vector<double> results;

    if(inp == 1){
        output_all(results);
    }
    else if(inp == 0) {
        exit(0); //Falls der Benutzer nichts ausgeben möchte
    }
    output_spec();

}

void NeuralNet::output_all(std::vector<double> &res_vals){ // Nimmt einen Vektor entgegen in dem die Resultate gespeichert werden sollen

    for(unsigned int i = 0; i < net_struct.back().size() - 1; i++){ // wir gehen für jede Neurone des letzten Layers durch (Outputlayer)
        res_vals.push_back(net_struct.back()[i].softMax(net_struct.back()[i].val)); // wir pushen die Resultate jeweils in einen Vektor mit den Resulataten der Neuronen
    }
}

void NeuralNet::output_spec(){
    unsigned int input_val;
    for(unsigned int i=0; i < net_struct.front().size();++i){
        std::cout << net_struct.front().size();
        std::cout << "Geben sie den Input val fuer Neuron Nr. " << i+1 <<" ein:";
        std::cin >> input_val;
        std::cout << "" <<std::endl;
        net_struct.front()[i].val.push_back(input_val); // Eingegbener Wert wird in den val vektor eines jeden Neurons gepuscht
    }
    for(unsigned int i=0;i<net_struct.size();i++){ // für jedes Layer
        for(unsigned int j=0;j<net_struct.at(i).size();j++){ // für jedes Neuron
            net_struct.at(i)[j].softMax(net_struct.at(i)[j].val); // softmax wird auf den eingegebenen val vektor angewendet an pos j
        }
    }
}

void NeuralNet::read_in(){
    int inp;
    std::cout<<"single file [1] or batch[0]";
    int numb=0;
    unsigned int num;
    std::ifstream file;
    std::string fileid;
    while(numb<2500){
        fileid = "qgp\\phsd50csr.auau.31.2gev.centr.0000phsd50csr.auau.31.2gev.centr."+ std::to_string(numb) + "_event.dat";
        file.open(fileid);
        while (file >> num){
                readin_val.push_back(num);
        }
        file.close();
        numb++;
    }



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
