/************************************************
 * Packet builder for NPU_model
 * This program is part of NPU_Model
 * Author: Soohyun Kim (soohyunkim@kw.ac.kr)
 * 
 ***********************************************/

#ifndef _H_NETWORK_
#define _H_NETWORK_

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "base_layer.h"

using namespace std;

class Network
{
private:
    std::string network_name;
    int layer_count = 0;
    bool i_fixed;
    int i_bit_width;
    bool w_fixed;
    int w_bit_width;
    std::vector<_base_layer*> layers;
public:
    Network(
        std::string network_name,
        bool i_fixed,
        int i_bit_width,
        bool w_fixed,
        int w_bit_width
    )
    : network_name{network_name}, i_fixed{i_fixed}, i_bit_width{i_bit_width},
      w_fixed{w_fixed}, w_bit_width{w_bit_width}
    {
    }

    void addLayer(_base_layer* new_layer)
    {
        if(new_layer == nullptr) throw runtime_error("null pointer detected");
        layers.push_back(new_layer);
        layer_count++;
    }

    ~Network()
    {
        for(auto l : layers) delete l;
    }
};

#endif