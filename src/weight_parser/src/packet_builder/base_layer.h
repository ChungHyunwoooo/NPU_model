/************************************************
 * Packet builder for NPU_model
 * This program is part of NPU_Model
 * Author: Soohyun Kim (soohyunkim@kw.ac.kr)
 * 
 ***********************************************/

#ifndef _H_BASELAYER_
#define _H_BASELAYER_

#include <iostream>
#include <string>
#include <map>

class _base_layer
{
protected:
    struct _base_inout
    {
        unsigned long long offset;
        unsigned long long size;

        _base_inout(
            unsigned long long offset,
            unsigned long long size
        )
        : offset{offset}, size{size} {}
        virtual ~_base_inout() {};
    };

    struct _1D_input : _base_inout
    {
        int width;
        _1D_input(
            int width,
            unsigned long long offset,
            unsigned long long size
        )
        : _base_inout{offset, size}, width{width} {}
    };

    struct _1D_kernel : _base_inout
    {
        int width;
         _1D_kernel(
            int width,
            unsigned long long offset,
            unsigned long long size
        )
        : _base_inout{offset, size}, width{width} {}
    };

    struct _1D_output : _base_inout
    {
        _1D_output(
            unsigned long long offset,
            unsigned long long size
        )
        : _base_inout{offset, size} {}
    };

    struct _2D_input : _base_inout
    {
        int width;
        int height;
        int channel;
        int padding;
        _2D_input(
            int width,
            int height,
            int channel,
            int padding,
            unsigned long long offset,
            unsigned long long size
        )
        : _base_inout{offset, size}, width{width}, height{height},
          channel{channel}, padding{padding} {}
    };

    struct _2D_kernel : _base_inout
    {
        int width;
        int height;
        int sets;
        int stride;
        _2D_kernel(
            int width,
            int height,
            int sets,
            int stride,
            unsigned long long offset,
            unsigned long long size
        )
        : _base_inout{offset, size}, width{width}, height{height},
          sets{sets}, stride{stride} {}
    };

    struct _2D_pooling : _base_inout
    {
        int p_type;
        int p_size;
        _2D_pooling(
            int p_type,
            int p_size
        )
        : _base_inout{0, 0}, p_type{p_type}, p_size{p_size} {}
    };

    struct _2D_output : _base_inout
    {
        int width;
        int height;
        _2D_output(
            int width,
            int height,
            unsigned long long offset,
            unsigned long long size
        )
        : _base_inout{offset, size}, width{width}, height{height} {}
    };

private:
    int layer_id;
    int layer_type;
    std::string layer_name;
    int activation;

protected:
    _base_inout* input = nullptr;
    _base_inout* kernel = nullptr;
    _base_inout* pooling = nullptr;
    _base_inout* output = nullptr;

public:
    _base_layer(
        int layer_id,
        int layer_type,
        std::string layer_name,
        int activation = 0 //default: without activation
    )
    : layer_id{layer_id}, layer_type{layer_type},
      layer_name{layer_name}, activation{activation}
    {
        
    }

    virtual ~_base_layer()
    {
        delete input;
        delete kernel;
        delete pooling;
        delete output;
    }

    int getLayerID() {return this->layer_id;} const
    void setLayerID(int layer_id) {this->layer_id = layer_id;}

    int getLayerType() {return this->layer_type;} const
    void setLayerType(int layer_type) {this->layer_type = layer_type;}

    const std::string& getLayerName() {return this->layer_name;} const
    void setLayerName(std::string layer_name) {this->layer_name = layer_name;}

    int getActivation() {return this->activation;} const
    void setActivation(int activation) {this->activation = activation;};

    const virtual std::map<std::string, unsigned long long> getInputProperty() = 0;
    virtual void setInputProperty() = 0;

    const virtual std::map<std::string, unsigned long long> getOutputProperty() = 0;
    virtual void setOutputProperty() = 0;
    
    const virtual std::map<std::string, unsigned long long> getPoolingProperty() 
    {
        return std::map<std::string, unsigned long long>();
    }
    virtual void setPoolingProperty() {}

    const virtual std::map<std::string, unsigned long long> getKernelProperty()
    {
        return std::map<std::string, unsigned long long>();
    }
    virtual void setKernelProperty() {}
};

#endif