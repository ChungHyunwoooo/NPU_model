/************************************************
 * Packet builder for NPU_model
 * This program is part of NPU_Model
 * Author: Soohyun Kim (soohyunkim@kw.ac.kr)
 * 
 ***********************************************/

#ifndef _H_LINEARLAYER_
#define _H_LINEARLAYER_

#include <iostream>
#include <string>

#include "base_layer.h"

class Linear : public _base_layer 
{
private:

public:
    Linear(
        int layer_id,
        int layer_type,
        std::string layer_name,
        //Linear input
        int i_width,
        unsigned long long i_offset,
        unsigned long long i_size,
        //Linear kernel
        int k_width,
        unsigned long long k_offset,
        unsigned long long k_size,
        //Activation
        int activation,
        //Linear output
        unsigned long long o_offset,
        unsigned long long o_size
    )
    : _base_layer{layer_id, layer_type, layer_name, activation}
    {
        //Set input and output variables
        this->input = new _1D_input
            {i_width, i_offset, i_size};
        this->kernel = new _1D_kernel
            {k_width, k_offset, k_size};
        this->output = new _1D_output
            {o_offset, o_size};
        //NOTE: delete will be handled in parent layer
    }

    ~Linear()
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