/*
Erster Versuch ein Neurales Netzwerk aus mehreren Neuronen aus 1 zusammen zusetzen
*/
#include <iostream>
#include <vector>

class Neuron{

};

typedef std::vector<Neuron> Layer; // Erstellt einen Vektor Namens Layer in dem  die Vektoren der Neuron Klasse ablegt werden

class NeuralNet:Neuron{
public:
    // 2a
    NeuralNet(const std::vector<unsigned> &topology);
    // 2b
    int output_all();
    // 2c
    int output_spec();
    // 2d
    int read_in();
    // 2e
    int backpropagation();
    // 2f
    int math_dist();
private:
    std::vector<Layer> net_struct; // Die Strucktur unseres Netzes,
                                   //Zugriff auf einzelne Neuronen/Vektoren: net_struct[layer_num][neuron_num]
};

NeuralNet::NeuralNet(const std::vector<unsigned> &topology){
    unsigned long long num_layer = topology.size();// Anzahl der Eingegebenen Werte für die Topologie (da frei wählbar)
    for(unsigned i = 0; i < num_layer ; i++){
        net_struct.push_back(Layer()); // Erstellt einen Layer(Vektor) in dem Objekt net_struct, welches ein Vektor von einem Vektor ist
        for(unsigned j = 0; j <= topology[i]; j++){ // Zugriff auf den eingegeben Wert um größe der Topologie abzufragen;
                                                    //<= um bias Neuron zu erstellen
            net_struct.back().push_back(Neuron());  // Mit .back greifen wir auf das zuletzt erstellte Element von net_struct zu
                                                    // .push_back speichert dann in dieser Position genau eine Instanz von Neuron ab
            std::cout << "Neuron erstellt"<<std::endl;
        }
    }
}

int main()
{
    std::vector<unsigned> topology;
    topology.push_back(1); //input für Topologie größe
    topology.push_back(2); //input für Topologie größe
    topology.push_back(3); //input für Topologie größe
    NeuralNet net(topology);

    return 0;
}

// Als Referenz: https://www.youtube.com/watch?v=KkwX7FkLfug
