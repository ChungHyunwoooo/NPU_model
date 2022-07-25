/************************************************
 * Packet builder for NPU_model
 * This program is part of NPU_Model
 * Author: Soohyun Kim (soohyunkim@kw.ac.kr)
 * 
 ***********************************************/

#ifndef _H_CONVLAYER_
#define _H_CONVLAYER_

#include <iostream>
#include <string>

#include "base_layer.h"

class Convolution2D : public _base_layer 
{
private:

public:
    Convolution2D(
        int layer_id,
        int layer_type,
        std::string layer_name,
        //Convolution input
        int i_width,
        int i_height,
        int i_channel,
        int i_padding,
        unsigned long long i_offset,
        unsigned long long i_size,
        //Convolution kernel
        int k_width,
        int k_height,
        int k_sets,
        int k_stride,
        unsigned long long k_offset,
        unsigned long long k_size,
        //Activation
        int activation,
        //Convolution output
        int o_width,
        int o_height,
        unsigned long long o_offset,
        unsigned long long o_size
    )
    : _base_layer{layer_id, layer_type, layer_name, activation}
    {
        //Set input and output variables
        this->input = new _2D_input
            {i_width, i_height, i_channel, i_padding, i_offset, i_size};
        this->kernel = new _2D_kernel
            {k_width, k_height, k_sets, k_stride, k_offset, k_size};
        this->output = new _2D_output
            {o_width, o_height, o_offset, o_size};
        //NOTE: delete will be handled in parent layer
    }

    ~Convolution2D()
    {

    }

    const std::map<std::string, unsigned long long> getInputProperty()
    {
        //TODO: impl
        return std::map<std::string, unsigned long long>();
    }
    void setInputProperty()
    {
        //TODO: impl
    }

    const std::map<std::string, unsigned long long> getOutputProperty()
    {
        //TODO: impl
        return std::map<std::string, unsigned long long>();
    }
    void setOutputProperty()
    {
        //TODO: impl
    }
    
    const std::map<std::string, unsigned long long> getKernelProperty()
    {
        //TODO: impl
        return std::map<std::string, unsigned long long>();
    }
    void setKernelProperty()
    {
        //TODO: impl
    }
};

#endif