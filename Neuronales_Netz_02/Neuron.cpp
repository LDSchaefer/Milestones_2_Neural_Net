#include <iostream>
#include <vector>
#include <math.h>
#include "Neuron.h"
#include <cstdlib>

Neuron::Neuron() ///unsigned out_num
{
    //Aufgabe a):

    for(unsigned int i = 0;i < 4; i++)
    {
        val.push_back(i); //Werte werden zurückgegeben
    }

    //testHidden();
    std::cout << "\n";

    softMax(val, 0); //Aktivierungsfunktion

    //sumHid(val);    //Hidden-Layer Gradient
    //outputGradient(val);
}

float Neuron::sum_ex(){
    //Aufgabe b):
    ///Hier wird die Summe der Werte zusammen gerechnet und zurückgegeben
    float sum = 0;
    float sum_hid = 0;
    return sum; // die Summe wird zurückgegeben
}

float Neuron::softMax(std::vector<unsigned> input_val, int pos){
    //Aufgabe b):
    ///Hier wird Softmax berechnet die s(x) = e^x / sum(e^x)
    ///Aktivierungsfnktion für den Output
    float sum = 0; //Für die erst Summe der Hidden-Layers
    float sum_out = 0; //Für den Output der summierten Hidden-Layer
    float sigmoid = 0; //Für den endgültigen Output
    std::cout << "Zufaellige weights w: " << weight << std::endl;
    deltaWeight.push_back(weight); //Die Gewichte werden in dieser Variable gespeichert und zurückgegeben.

    float hid = 0; //Diese Variable speichert die Zwischenberechnung der Inputs
    for(unsigned int i = 0; i < input_val.size(); i++) // für jeden wert des eingegebenen vektors wird der e hoch i berechnet
    {
        //Hier werden die Inputs mit dem Gewicht (Kanten) multipliziert
        std::cout << " Inputs x: " << i << std::endl;
        sum += input_val.at(i) * weight; //Die Summe der Gewichte und Inputs

        ///Zusätzlich werden zufällige Zahlen multipliziert, die die Weights sind
        ///w[l] = rand(0:1)
        /// p1 * w1 -->
        /// p2 * w2 -->
        /// p3 * w3 -->
        /// ...
        /// pn * wn -->
        /// Siehe Plenartfolie_03 Seite 5
    }
    std::cout << "\n";
    //Ausgabe der Hidden-Layers
    std::cout << "Output von der Summe der Hidden-Layer Gradient L: " << sum << std::endl;
    std::cout << "\n";
    // Der Wert an der gegebenen Position (i auf Blatt) wird durch sum geteilt
    float sigma = (1 / (1 + std::exp(-sum))); //Aktivierungsfunktion

    std::cout << "Hidden-Layer Output Softmax1(" << sum << ") = " << sigma << "\n";
    std::cout << "\n";
    sum_out += sigma * weight;
    sigmoid = (1 / (1 + std::exp(-sum_out))); //Aktivierungsfunktion Softmax
    std::cout << "Output der Softmax2(" << sum_out << "): " << sigmoid << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------"<<"\n";
    outVal.push_back(sigma); //Hier werden die Werte gespeichert
    outVal.push_back(sigmoid);
    return sigma; // der erhaltene Wert wird zurückgegeben
}

///Diese Funktion sorgt dafür, dass eine Verbindung zwischen Neuronen von Layer i und Layer i + 1,
///mitsamt einer Möglichkeit die Gewichte zu hinterlegen.

float Neuron::derivation(std::vector<unsigned> output_val){
    //Aufgabe b):
    ///Die Ableitungsfunktion sigmoid'(x) = 1 / 1 + e^-x dinet für das Lernen des Netzwerkes
    float exp_deriv = 0;
    for(int i = 0; i < output_val.size(); i++){
        //exp_deriv = 1 / 1 + std::exp(-i); ///Die Ableitung für die Backpropagation
        //exp_deriv = (sigma * (1 - sigma)); //Die wahre Ableitung der Softmax Funktion: f'(x) = S * (1 - S)
    }
    //return exp_deriv;
}

float Neuron::sumHid(std::vector<unsigned> input_val){
    //Aufgabe c):
    ///Die Hidden Funktion berechnet die jeweiligen Inputs mit ihren Gewichtungen
    /// berechnet werden:
    ///
    /// input1 * weights + input2 * weights = hidden
    /// 1 * 0.8 + 1 * 0.2 = 1
    ///1 * 0.4 + 1 * 0.9 = 1.3
    ///1 * 0.3 + 1 * 0.5 = 0.8
    float hid = 0; //Diese Variable speichert die Zwischenberechnung der Inputs
    double sum_hid = 0; //Die Summe der Hidden-Layer wird berechnet

    for(int i = 0; i < input_val.size(); i++){
        sum_hid += weight * input_val.at(i); //hidden-Layer = wi * xi
        ///std::cout << "Die Gewichtung weight[" << i << "]:" << weight << std::endl;
        std::cout << "Die Summe der Hidden-Layer[" << i << "]: " << sum_hid << std::endl;
    }
    std::cout << "\n";
    return hid;
}

float Neuron::outputGradient(std::vector<unsigned> input_val){
    ///hidden_1 = 10 * (layer_1) + 0 * (layer_2) + 2 * (layer_3)
    /// Hier soll die Output-Gradient für output-Layer für andere Hidden-Gradient für alle Hidden-Layer
    float sig_outn; //Für den Output Layer Gradient Berechnung:
    for(int i = 0; i < input_val.size(); i++){
        //om = (tm - f(xm)) * f'(xm):

    }
}


/*
float Neuron::testHidden(){
    float s (0);
    float s2 (0);
    float f;
    float f2;
    std::vector<float> myvec;
    myvec.push_back(1);
    myvec.push_back(2);
    myvec.push_back(3);

    for(int i = 0; i < myvec.size(); i++){
        //std::cout << "Zufaellige weights w" << i << ": " << weight << std::endl;
        //std::cout << "Die Input : x" << i << ": " << myvec.at(i) << std::endl;

        s += weight * myvec.at(i); //Jedes Element wird mit seiner zufälligen Gewichtung multipliziert.
    }

    std::cout << "S(x): " << s << std::endl;
    f = (1/(1+exp(s)));
    std::cout << "Die Hidden-Layer sind: f(" << s << ") = " << f << std::endl;
    std::cout << "\n";
    s2 += s * weight;
    std::cout << "Hidden-Layer(x): " << s2 << std::endl;
    f2 = (1 / (1 + std::exp(s2)));
    std::cout << "Die Softmax-Funktion: f2(" << s << ") = " << f2 << std::endl;
    myvec.pop_back();
}
*/
