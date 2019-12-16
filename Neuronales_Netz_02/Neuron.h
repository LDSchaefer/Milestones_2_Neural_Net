#ifndef NEURON_H
#define NEURON_H

#endif // NEURON_H

#include <vector>
#include <iostream>

class Neuron; //Aufgabe 1 a)

typedef std::vector<Neuron> Layer; // Erstellt einen Vektor Namens Layer in dem  die Vektoren der Neuron Klasse ablegt werden
                                   // Muss evtl. ebenfalls in .h ausgelagert werden
class Neuron{ // Dummy Klasse
public:

    std::vector<unsigned int> val ; //Hier werden die Werte gespeichert und  zurückgegeben
    std::vector<float> outVal; //Dieser Vector speichert die Hidden-Layer
    std::vector<float> hidden;
    std::vector<float> deltaWeight; //Diese Varaiable speichert die weights

    Neuron(); ///Anzahl der Outputs
    ///unsigned out_Num
    ///
    double sigma; //transfer function from the inputs
    //sum of the vector

    double sum;
    float softMax(std::vector<unsigned> input_val);
    float derivation(std::vector<unsigned> output_val);

    float sum_ex(); //Gib die Summe der Aktivierungsberechnung zurück
    double weight = rand() / double(RAND_MAX); ///Weight Randomzahlen von 0 bis 1

    ///d)
    /// Funktion, mit der zum einen die Output-Gradienten
    /// für Output-LayerNeuronen, zum anderen die Hidden-Gradienten
    /// für alle Hidden-Layer berechnet werden können
    float outputGradient(std::vector<unsigned> input_val);
    float sumHid(float sum_layer); //Gibt jeweils die Hidden-Layer aus

    //float testHidden();
};
