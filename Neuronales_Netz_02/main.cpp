#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <math.h>


class Channel
{
private:

    int ranNum;
    float weight;  // Kernel-Gewicht
    //weight = rand() / float(RAND_MAX);  //Generates random number from 0 to 1
    float maxLReLu;
    float matrixLayer[0][0][0];


public:

    void conv3D(){
        // 28 x 22x22x22-Matrix X:
        matrixLayer[22][22][22] = 0;

    }

    void getChannel(){
        // 2) 20x20x20 to 10x10x10 get max
        // 4) MaxPool3D 10x10x10 to 5x5x5
        //
    }

    void setChannel(){
    }

    void addChannel(){
        ranNum = rand() % 10; // Erzeuge Random Zahlen von 0 bis 10

    }

    void clearChannel(){
        /* Die Clear-Funktion leert die Klasse */
    }

    float lReLu(float x){
      // Lineare Aktivierungsfunktion
      // f(x) = max(0.01*x, x) Leaky ReLu:
      //  ^
      //  |              /
      //  |             /
      //  |            /
      //  |           /
      //  |          /
      //  |         /
      //  |        /
      //  |       /
      //--|------/------------------------->
      //  |_____/
        //maxLReLu = std::max_element(0, x);
        //std::cout << std::max(0.0, x);
        return maxLReLu;
    }


};

class Kernell
{
private:

    int n;

    float weight;  // Kernel-Gewicht
    float * matrix = new float;  // 20x20x20 x 28 Matrix
    float wMatrix[3][3][3];

public:


    float reset(){
        n = 3; // Größe der Matrix.
        // Weight 3x3x3 matrix
        //   ________________
        // /                /|
         //________________/ |
       // |w0,0| w0,1| w0,2| |
       // |w1,0| w1,1| w1,2| |
       // |w2,0| w2,1| w2,2|/
       // ------------------
        wMatrix[n][n][n] = 0; // 3x3x3-Matrix

        // Fülle die Matrix mit Randomzahlen auf:
        for(int i = 0; i < sizeof (wMatrix); i++){
            weight = (rand()/float(RAND_MAX));
            wMatrix[i][i][i] = { weight };

            // Printe die 3x3x3-Matrix:
            std::cout << wMatrix[i][i][i] << " ";
        }
        std::cout << std::endl;
        //std::cout << "Die Groesse der Matrix: " << sizeof (wMatrix) << "\n";


    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Channel channel;
    Kernell kernell;
    kernell.reset();
    return 0;
}
