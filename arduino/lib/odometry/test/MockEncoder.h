#ifndef MOCK_ENCODER_H
#define MOCK_ENCODER_H
#include "Encoder.h"

class MockEncoder : public Encoder
{
public:
   float RevolutionsPerSecond() { return m_rps; }
   Direction GetDirection() const { return m_direction; }
   void SetRevolutionsPerSecond(const float newFrequency) { m_rps = newFrequency; }
   void SetDirection(const Direction direction) { m_direction = direction; }
   float GetFrequency() { return 0; } // not implemented

private:
   float m_rps;
   Direction m_direction;
};


#endif /* end of include guard: MOCK_ENCODER_H */
