#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include <inttypes.h>
#include "Encoder.h"
#include <Arduino.h>

enum Wheel { LEFT, RIGHT };

template<Wheel interruptPin>
class RotaryEncoder : public Encoder
{
public:
    RotaryEncoder(float ratio);

    virtual float RevolutionsPerSecond() const;
    virtual float GetFrequency() const;
    virtual Direction GetDirection() const;

    static void Handler();

};

template<Wheel interrupt>
inline RotaryEncoder<interrupt>::RotaryEncoder(float ratio) {
    attachInterrupt(0, Handler, RISING);
}

template<Wheel interrupt>
inline float RotaryEncoder<interrupt>::RevolutionsPerSecond() const {

}

template<Wheel interrupt>
inline float RotaryEncoder<interrupt>::GetFrequency() const {

}

template<Wheel interrupt>
inline Encoder::Direction RotaryEncoder<interrupt>::GetDirection() const {
}

template<Wheel interrupt>
inline void RotaryEncoder<interrupt>::Handler() {

}

#endif /* end of include guard: ROTARY_ENCODER_H */
