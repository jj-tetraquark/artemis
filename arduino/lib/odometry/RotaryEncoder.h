#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include <inttypes.h>
#include "Encoder.h"

class RotaryEncoder : public Encoder
{
public:
    RotaryEncoder(uint8_t interrupt);

    virtual float GetFrequency() const;

};


#endif /* end of include guard: ROTARY_ENCODER_H */
