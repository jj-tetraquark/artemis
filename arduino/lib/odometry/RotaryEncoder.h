#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <inttypes.h>
#include "Encoder.h"
#include "Arduino.h"
#include <iostream>

enum Wheel { LEFT, RIGHT };
const float FREQUENCY_POLL_TIMEOUT_S = 0.2;

template<Wheel interruptPin>
class RotaryEncoder : public Encoder {
public:
    RotaryEncoder(uint8_t encoderInputA, uint8_t encoderInputB, float ratio);

    virtual float RevolutionsPerSecond();
    virtual float GetFrequency();
    virtual Direction GetDirection() const { return m_direction; }

    static void Handler();

    static constexpr int RotaryEncoderMatrix[] = {0,BACKWARDS,FORWARDS,2, 
                                                  FORWARDS,0,2,BACKWARDS, 
                                                  BACKWARDS,2,0,FORWARDS, 
                                                  2,FORWARDS, BACKWARDS,0};   

private:
    void IncreasePulseCount();
    void InferDirection();

    static RotaryEncoder*   m_instance; 
    uint8_t                 m_inputA;
    uint8_t                 m_inputB;

    Direction               m_direction;
    unsigned long           m_pulseCount;
    unsigned long           m_lastTimeStamp;
    float                   m_lastFrequency;
    float                   m_ratio;
    int                     m_previousEncoderReading;

};

#include "RotaryEncoder.hpp"
#endif /* end of include guard: ROTARY_ENCODER_H */
