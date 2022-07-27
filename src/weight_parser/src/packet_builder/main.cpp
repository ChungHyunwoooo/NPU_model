/************************************************
 * Packet builder for NPU_model
 * This program is part of NPU_Model
 * Author: Soohyun Kim (soohyunkim@kw.ac.kr)
 * 
 ***********************************************/

#include <iostream>
#include <string>
#include <fstream>

#include "base_layer.h"
#include "convolution.h"
#include "pooling.h"
#include "linear.h"
#include "network.h"

using namespace std;

int main(int argc, char* argv[])
{
    //Sample building
    Network *net = new Network{"LeNet-5", 0, 0, 0, 0};

    Convolution2D *C1 = new Convolution2D {
        0, 0, "C1",
        32, 32, 1, 0, 0, 4096,
        5, 5, 6, 1, 4096, 600, 
        1,
        28, 28, 4696, 18816
    };

    Pooling *S2 = new Pooling {
        1, 1, "S2",
        28, 28, 6, 4696, 18816,
        1, 2,
        14, 14, 23512, 4704
    };

    Convolution2D *C3 = new Convolution2D {
        2, 0, "C3",
        14, 14, 6, 0, 23512, 4704, 
        5, 5, 16, 1, 28216, 9600, 
        1, 
        10, 10, 37816, 6400
    };

    Pooling *S4 = new Pooling {
        3, 1, "S4",
        10, 10, 16, 37816, 6400,
        1, 2,
        5, 5, 44216, 1600
    };

    Convolution2D *C5 = new Convolution2D {
        4, 0, "C5",
        5, 5, 120, 0, 44216, 1600,
        5, 5, 120, 1, 45816, 192000,
        1, 
        1, 1, 237816, 480
    };

    Linear *F6 = new Linear {
        5, 2, "F6",
        120, 237816, 480,
        84, 238296, 40320,
        1, 
        278616, 336
    };

    Linear *OUT = new Linear {
        6, 2, "OUT",
        84, 278616, 336,
        10, 278952, 3360,
        1, 
        282312, 40
    };


    net->addLayer(C1);
    net->addLayer(S2);
    net->addLayer(C3);
    net->addLayer(S4);
    net->addLayer(C5);
    net->addLayer(F6);
    net->addLayer(OUT);



    delete net;
    return 0;
}