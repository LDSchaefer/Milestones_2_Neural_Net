#include <iostream>
#include <vector>
#include <math.h>
#include "Neuron.h"
#include <cstdlib>

Neuron::Neuron() ///unsigned out_num
{
    for(unsigned int i = 0;i < 3; i++)
    {
        val.push_back(i);
    }
    softMax(val, 0);
/*
    for(unsigned connct = 0; connct < out_num; connct++){
        weights_out.push_back(Connection()); ///Die wights werden neue Elemente hinzugefügt von der Struc Connection
        /// werden Random Zahlen von 0 bis 1 zufällig ausgewählt und in dem weight hinzugefügt
        weights_out.back().weight = rand_wights();
    }
*/
}

///Hier wird die Summe der Werte zusammen gerechnet und zurückgegeben
float Neuron::sum_ex(){
    float sum = 0;
    return sum;
}
///Hier wird Softmax berechnet
float Neuron::softMax(std::vector<unsigned> input_val, int pos){
    float sum = 0;

    std::cout << "Zufaellige weights w: " << weight << std::endl;

    for(unsigned int i = 0; i < input_val.size(); i++) // für jeden wert des eingegebenen vektors wird der e hoch i berechnet
    {

        float ex = std::exp(input_val.at(i)) * weight;
        sum = sum + ex; // alle Werte werden in sum addiert
        ///Zusätzlich werden zufällige Zahlen multipliziert, die die Weights sind
        ///w[l] = rand(0:1)
        /// p1 * w1 -->
        /// p2 * w2 -->
        /// p3 * w3 -->
        /// ...
        /// pn * wn -->
        /// Siehe Plenartfolie_03 Seite 5

    }

    float sigma = std::exp(input_val.at(pos))/sum; // Der Wert an der gegebenen Position (i auf Blatt) wird durch sum geteilt
    std::cout << "" << sigma << "\n";
    return sigma; // der erhaltene Wert wird zurückgegeben
}

///Diese Funktion sorgt dafür, dass eine Verbindung zwischen Neuronen von Layer i und Layer i + 1,
///mitsamt einer Möglichkeit die Gewichte zu hinterlegen.

float Neuron::sumHid(const Layer &nextLayer){
    double sum_hid = 0.0; //Die Summe der Hidden-Layer wird berechnet
    std::vector<float> m_weights;  //Weights
    float prob = m_weights[0];
    for(int i = 0; i < nextLayer.size(); i++){
        //prob += nextLayer[i] * m_weights[i + 1];
    }
}

float Neuron::outputGradient(const Layer &nextLayer){
    ///hidden_1 = 10 * (layer_1) + 0 * (layer_2) + 2 * (layer_3)
    /// Hier soll die Output-Gradient für output-Layer für andere Hidden-Gradient für alle Hidden-Layer
    /// berechnet werden:
    ///
    /// input1 * weights + input2 * weights = hidden
    /// 1 * 0.8 + 1 * 0.2 = 1
    ///1 * 0.4 + 1 * 0.9 = 1.3
    ///1 * 0.3 + 1 * 0.5 = 0.8
}
