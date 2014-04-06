#ifndef MOCK_ENCODER_H
#define MOCK_ENCODER_H
#include "Encoder.h"

class MockEncoder : public Encoder
{
public:
   float GetFrequency() const { return m_frequency; }
   Direction GetDirection() const { return m_direction; }
   void SetFrequency(const float newFrequency) { m_frequency = newFrequency; }
   void SetDirection(const Direction direction) { m_direction = direction; }

private:
   float m_frequency;
   Direction m_direction;
};


#endif /* end of include guard: MOCK_ENCODER_H */
