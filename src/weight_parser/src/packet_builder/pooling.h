/************************************************
 * Packet builder for NPU_model
 * This program is part of NPU_Model
 * Author: Soohyun Kim (soohyunkim@kw.ac.kr)
 * 
 ***********************************************/

#ifndef _H_POOLLAYER_
#define _H_POOLLAYER_

#include <iostream>
#include <string>

#include "base_layer.h"

class Pooling : public _base_layer 
{
private:

public:
    Pooling(
        int layer_id,
        int layer_type,
        std::string layer_name,
        //Pooling input
        int i_width,
        int i_height,
        int i_channel,
        unsigned long long i_offset,
        unsigned long long i_size,
        //Pooling config
        int p_type,
        int p_size,
        //Convolution output
        int o_width,
        int o_height,
        unsigned long long o_offset,
        unsigned long long o_size
    )
    : _base_layer{layer_id, layer_type, layer_name}
    {
        //Set input and output variables
        this->input = new _2D_input
            {i_width, i_height, i_channel, 0, i_offset, i_size};
        this->pooling = new _2D_pooling
            {p_type, p_size};
        this->output = new _2D_output
            {o_width, o_height, o_offset, o_size};
        //NOTE: delete will be handled in parent layer
    }

    ~Pooling()
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
    
    const std::map<std::string, unsigned long long> getPoolingProperty()
    {
        //TODO: impl
        return std::map<std::string, unsigned long long>();
    }
    void setPoolingProperty()
    {
        //TODO: impl
    }
};

#endif