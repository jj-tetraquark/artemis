#include "Arduino.h"
#include "Config.h"
#include "PIDControlledMotor.h"
#include "Encoder.h"

PIDControlledMotor::PIDControlledMotor
    (const unsigned int wheelRadius, const Motor& motor, Encoder* const encoder,
     const float kP, const float kI, const float kD)
    : m_wheelCircumference(2 * PI * wheelRadius), 
      m_motor(motor),
      m_encoder(encoder),
      m_targetVelocity(0),
      m_previousError(0),
      m_errorIntegral(0),
      m_errorDerivative(0),
      m_proportionalGain(kP), 
      m_integralGain(kI),
      m_derivativeGain(kD) {
}

PIDControlledMotor::PIDControlledMotor
    (const unsigned int wheelRadius, const Motor& motor, Encoder* const encoder): 
    PIDControlledMotor(wheelRadius, 
                       motor,
                       encoder,
                       Config::PID::K_PROPORTIONAL,
                       Config::PID::K_INTEGRAL, 
                       Config::PID::K_DIFFERENTIAL) { 
}

void PIDControlledMotor::Update() {
    float currentVelocity = m_encoder->RevolutionsPerSecond() * m_wheelCircumference 
                                * m_encoder->GetDirection();

    float error = m_targetVelocity - currentVelocity;
    m_errorDerivative = error - m_previousError;
    m_errorIntegral += error;
    m_previousError = error;

    int control = m_proportionalGain * error 
                  + m_integralGain * m_errorIntegral 
                  + m_derivativeGain * m_errorDerivative;
    
    m_motor.SetSpeed(control);
}
