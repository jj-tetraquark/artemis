#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include <inttypes.h>
#include "Encoder.h"
#include <Arduino.h>

enum Wheel { LEFT, RIGHT };
const float FREQUENCY_POLL_TIMEOUT_S = 0.2;

template<Wheel interruptPin>
class RotaryEncoder : public Encoder
{
public:
    RotaryEncoder(float ratio);

    virtual float RevolutionsPerSecond();
    virtual float GetFrequency();
    virtual Direction GetDirection() const;

    static void Handler();

private:
    void IncreasePulseCount();

    static RotaryEncoder*   m_instance; 
    unsigned int            m_pulseCount;
    unsigned long           m_lastTimeStamp;
    float                   m_lastFrequency;
    float                   m_ratio;

};

template<Wheel interrupt>
RotaryEncoder<interrupt>* RotaryEncoder<interrupt>::m_instance = nullptr;

template<Wheel interrupt>
RotaryEncoder<interrupt>::RotaryEncoder(float ratio) : m_pulseCount(0), m_lastTimeStamp(micros()), m_ratio(ratio) {
    m_instance = this;
    attachInterrupt(interrupt, Handler, RISING);
}

template<Wheel interrupt>
float RotaryEncoder<interrupt>::RevolutionsPerSecond() {
    return GetFrequency() * m_ratio;
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
Encoder::Direction RotaryEncoder<interrupt>::GetDirection() const {
}

template<Wheel interrupt>
void RotaryEncoder<interrupt>::IncreasePulseCount() {
    m_pulseCount++;
}

template<Wheel interrupt>
void RotaryEncoder<interrupt>::Handler() {
    m_instance->IncreasePulseCount();
}

#endif /* end of include guard: ROTARY_ENCODER_H */
