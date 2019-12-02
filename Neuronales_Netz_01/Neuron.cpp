#include <iostream>
#include <vector>
#include <math.h>
#include "Neuron.h"

int Neuron::neuron_res()
{
  std::cout << "helloworld"<<std::endl; // Hier stände jetzt das Resultat einer Neurone

  }

float Neuron::sum_ex(){

    return sum;
}

void Neuron::softMax(){
     //Sigma function sigmoid(x) = (std::exp(-x)/sum(std::exp(-x))
  //sum = std::accumulate(begin(x), end(x), 0.0);

    //Exponential function
        //double exp_sum = std::exp(sum);
        //layer = {1, 0.9, 0.4};
    for(int i = 0; i < Layer()[i].size(); i++)
    {
        float ex = std::exp(Layer[i]);
        //float sum_exp = layer[i] / std::accumulate(begin(i), end(i), 0.0);
        std::cout << "" << ex << "\n" ;
    }
}
        //sigma = std::exp(x) / accumulate(std::exp(x))

        //std::cout << "The sum of vector is: " << sum << "\n";
        //std::cout << "The Calculation of exp sum is: " << exp_sum << "\n";

        //float sigma = (1.0 / 1.0 + std::exp(-x));
        //std::cout << sigma << "\n";

        //The tan function calculates
        //float tan = tanh(x);
        //std::cout << tan << "\n";

        //Calculate the Vectors
        //std::vector <double>;

