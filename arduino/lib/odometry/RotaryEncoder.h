#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <inttypes.h>
#include "Encoder.h"
#include "Arduino.h"
#include <iostream>

enum Wheel { LEFT, RIGHT };
const float FREQUENCY_POLL_TIMEOUT_S = 0.2;



template<Wheel interruptPin>
class RotaryEncoder : public Encoder
{
public:
    RotaryEncoder(uint8_t encoderInputA, uint8_t encoderInputB, float ratio);

    virtual float RevolutionsPerSecond();
    virtual float GetFrequency();
    virtual Direction GetDirection() const { return m_direction; }

    static void Handler();

    static constexpr int RotaryEncoderMatrix[] = {0,-1,1,2, 1,0,2,-1, -1,2,0,1, 2,1,-1,0};   

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

template<Wheel interrupt>
RotaryEncoder<interrupt>* RotaryEncoder<interrupt>::m_instance = nullptr;

template<Wheel interrupt>
constexpr int RotaryEncoder<interrupt>::RotaryEncoderMatrix[];

template<Wheel interrupt>
RotaryEncoder<interrupt>::RotaryEncoder(uint8_t encoderInputA, uint8_t encoderInputB, float ratio) 
    : m_pulseCount(0), m_lastTimeStamp(micros()), m_ratio(ratio), m_previousEncoderReading(0), 
    m_inputA(encoderInputA), m_inputB(encoderInputB) {
    m_instance = this;
    attachInterrupt(interrupt, Handler, RISING);
    pinMode(encoderInputA, INPUT); 
    pinMode(encoderInputB, INPUT); 
}

template<Wheel interrupt>
float RotaryEncoder<interrupt>::RevolutionsPerSecond() {
    return GetFrequency() * m_ratio * (m_direction == Direction::FORWARDS ? 1 : -1);
}

template<Wheel interrupt>
float RotaryEncoder<interrupt>::GetFrequency() {
    unsigned long currentTime = micros();
    float period = (currentTime - m_lastTimeStamp)/1000000.0; // convert to seconds
    if (period < FREQUENCY_POLL_TIMEOUT_S) { 
        return m_lastFrequency;
    }
    
    m_lastFrequency = m_pulseCount/period;
    m_lastTimeStamp = currentTime;
    m_pulseCount = 0;

    return m_lastFrequency;
}

template<Wheel interrupt>
void RotaryEncoder<interrupt>::Handler() {
    m_instance->IncreasePulseCount();
    m_instance->InferDirection();
}

template<Wheel interrupt>
void RotaryEncoder<interrupt>::IncreasePulseCount() {
    m_pulseCount++;
}

template<Wheel interrupt>
void RotaryEncoder<interrupt>::InferDirection() {
    int const newReading = digitalRead(m_inputA) * 2 + digitalRead(m_inputB); // read and convert to binary representation
    int const direction = RotaryEncoder::RotaryEncoderMatrix[m_previousEncoderReading * 4 + newReading];
    
    if(direction == 1) {
        m_direction = Direction::FORWARDS;
    } else if (direction == -1) {
        m_direction = Direction::BACKWARDS;
    }
    m_previousEncoderReading = newReading; 
}
#endif /* end of include guard: ROTARY_ENCODER_H */
