#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include <inttypes.h>
#include "Encoder.h"

class RotaryEncoder : public Encoder
{
public:
    RotaryEncoder(uint8_t interrupt);

};


#endif /* end of include guard: ROTARY_ENCODER_H */