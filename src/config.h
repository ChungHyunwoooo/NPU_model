
#include <systemc.h>
template <typename T>
class convolution_configuration<T>
{
    T i_width;
    T i_height;
    T i_channel;
    T i_size; // Total size of input feature map, W*H*C
    T i_padding;
    T i_offset;

    T k_width;
    T k_height;
    T k_channel;
    T k_sets;
    T k_size; // Total size of input feature map, W*H*C*S
    T k_padding;

    T o_width;
    T o_height;
    T o_channel;
    T o_size;
    T o_offset;
}