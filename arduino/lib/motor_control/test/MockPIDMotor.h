#ifndef MOCK_PID_MOTOR_H
#define MOCK_PID_MOTOR_H
#include "FeedbackControlledMotor.h"

class MockPIDMotor : public FeedbackControlledMotor
{
public:
    MockPIDMotor() : m_updateCallCount(0), m_targetVelocity(0) {}
    void SetVelocity(const float velocity) { m_targetVelocity = velocity; }
    void Update() { m_updateCallCount++; }

    float GetVelocity() const { return m_targetVelocity; }
    int GetUpdateCallCount() const { return m_updateCallCount; }

private:
    int m_updateCallCount;
    float m_targetVelocity;
};


#endif /* end of include guard: MOCK_PID_MOTOR_H */
