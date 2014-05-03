template<Wheel interrupt>
RotaryEncoder<interrupt>* RotaryEncoder<interrupt>::m_instance = nullptr;

template<Wheel interrupt>
constexpr int RotaryEncoder<interrupt>::RotaryEncoderMatrix[];

template<Wheel interrupt>
RotaryEncoder<interrupt>::RotaryEncoder(uint8_t encoderInputA, uint8_t encoderInputB, float ratio) 
    : m_pulseCount(0), m_lastTimeStamp(micros()), m_ratio(ratio), m_previousEncoderReading(0), 
    m_inputA(encoderInputA), m_inputB(encoderInputB), m_direction(FORWARDS) {
    m_instance = this;
    attachInterrupt(interrupt, Handler, RISING);
    pinMode(encoderInputA, INPUT); 
    pinMode(encoderInputB, INPUT); 
}

template<Wheel interrupt>
float RotaryEncoder<interrupt>::RevolutionsPerSecond() {
    return GetFrequency() * m_ratio * m_direction;
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
    if(direction == FORWARDS || direction == BACKWARDS) { // ignore errors, basically
        m_direction = static_cast<Encoder::Direction>(direction);
    }

    m_previousEncoderReading = newReading; 
}

