#ifndef MOCK_PID_MOTOR_H
#define MOCK_PID_MOTOR_H
#include "FeedbackControlledMotor.h"

class MockPIDMotor : public FeedbackControlledMotor
{
public:
    void SetVelocity(const float velocity) { m_targetVelocity = velocity; }
    void Update() {}

    float GetVelocity() const { return m_targetVelocity; }

private:
    float m_targetVelocity;
};


#endif /* end of include guard: MOCK_PID_MOTOR_H */
