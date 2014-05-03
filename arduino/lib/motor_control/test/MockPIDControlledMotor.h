#ifndef MOCK_PID_CONTROLLED_MOTOR
#define MOCK_PID_CONTROLLED_MOTOR

class MockPIDControlledMotor 
{
public:
    void SetVelocity(const float velocity) { m_targetVelocity = velocity; }
    void Update() {}
private:
    float m_targetVelocity;
};

#endif /* end of include guard: MOCK_PID_CONTROLLED_MOTOR */
