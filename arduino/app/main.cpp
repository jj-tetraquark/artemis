#include <Arduino.h>
#include "Motor.h"
#include "TwoWheelOdometryManager.h"
#include "RotaryEncoder.h"

Motor leftMotor(2,3);
Motor rightMotor(8,9);


void loop() {
    for(int speed = 0; speed < 100; speed++) {
        delay(5);
        leftMotor.SetSpeed(speed);
        rightMotor.SetSpeed(speed);
    }
    for(int speed = 100; speed > 0; speed--) {
        delay(5);
        leftMotor.SetSpeed(speed);
        rightMotor.SetSpeed(speed);
    }
}

int main()
{
    leftMotor.SetDirectionForwards();
    rightMotor.SetDirectionBackwards();
    init();
    while(true)
        loop();
    return 0;
}
