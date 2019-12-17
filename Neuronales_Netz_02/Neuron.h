#ifndef NEURON_H
#define NEURON_H

#endif // NEURON_H

#include <vector>
#include <iostream>

class Neuron; //Aufgabe 1 a)

typedef std::vector<Neuron> Layer; // Erstellt einen Vektor Namens Layer in dem  die Vektoren der Neuron Klasse ablegt werden
                                   // Muss evtl. ebenfalls in .h ausgelagert werden
//Aufgabe a)
class Neuron{ // Dummy Klasse
public:

    //Attributen des Neurons:

    double weight = rand() / double(RAND_MAX); //Zufällige Zahlen von 0 bis 1 werden gewählt

    std::vector<unsigned int> val ;         //Hier werden die Werte gespeichert und  zurückgegeben.
    std::vector<float> outVal;              //Dieser Vector speichert die Hidden-Layer.
    std::vector<float> hidden;              //Die Hidden-Layer werden in dem Vektor gespeichert.
    std::vector<float> deltaWeight;         //Diese Varaiable speichert die weights.

    Neuron(); ///Anzahl der Outputs

    double sigma;                           //transfer function from the inputs
    //sum of the vector
    std::vector<float> vec;                 //Die Inputs * Weights werden unter diesem Vektor gespeichert.

    double sum;                             //Die Summe aller Inputs und Gewichte

    //Methoden des Neurons:
    float weightUpdate();                   //Aufgabe f)
    float softMax(std::vector<unsigned int> input);      //Aufgabe b)
    float derivation();  //Aufgabe b) Ableitung der Softmax()
    float sum_ex();                         //Gib die Summe der Aktivierungsberechnung zurück

    //Aufgabe 1 d) und e)
    /// Funktion, mit der zum einen die Output-Gradienten
    /// für Output-LayerNeuronen, zum anderen die Hidden-Gradienten
    /// für alle Hidden-Layer berechnet werden können
    float outputGradient(std::vector<unsigned int> input_val);
    float sumHid(); //Gibt jeweils die Hidden-Layer aus

    //float testHidden();
};
