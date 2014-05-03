template<Wheel side>
RotaryEncoder<side>* RotaryEncoder<side>::m_instance = nullptr;

template<Wheel side>
constexpr int RotaryEncoder<side>::RotaryEncoderMatrix[];

template<Wheel side>
RotaryEncoder<side>::RotaryEncoder(uint8_t encoderInputA, uint8_t encoderInputB, float ratio) 
    : m_pulseCount(0), m_lastTimeStamp(micros()), m_ratio(ratio), m_previousEncoderReading(0), 
    m_inputA(encoderInputA), m_inputB(encoderInputB), m_direction(FORWARDS) {
    m_instance = this;
    attachInterrupt(side, Handler, RISING);
    pinMode(encoderInputA, INPUT); 
    pinMode(encoderInputB, INPUT); 
}

template<Wheel side>
float RotaryEncoder<side>::RevolutionsPerSecond() {
    return GetFrequency() * m_ratio * m_direction;
}

template<Wheel side>
float RotaryEncoder<side>::GetFrequency() {
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

template<Wheel side>
void RotaryEncoder<side>::Handler() {
    m_instance->IncreasePulseCount();
    m_instance->InferDirection();
}

template<Wheel side>
void RotaryEncoder<side>::IncreasePulseCount() {
    m_pulseCount++;
}

template<Wheel side>
void RotaryEncoder<side>::InferDirection() {
    int const newReading = digitalRead(m_inputA) * 2 + digitalRead(m_inputB); // read and convert to binary representation
    int const direction = RotaryEncoder::RotaryEncoderMatrix[m_previousEncoderReading * 4 + newReading];
    if(direction == FORWARDS || direction == BACKWARDS) { // ignore errors, basically
        m_direction = static_cast<Encoder::Direction>(direction);
    }

    m_previousEncoderReading = newReading; 
}

