#ifndef MOCK_ENCODER_H
#define MOCK_ENCODER_H
#include "Encoder.h"

class MockEncoder : public Encoder
{
public:
   float GetFrequency()  { return m_frequency; }
   void SetFrequency(float newFrequency) { m_frequency = newFrequency; }

private:
   float m_frequency;
};


#endif /* end of include guard: MOCK_ENCODER_H */
