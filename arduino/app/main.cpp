#include <Arduino.h>
#include "Motor.h"

Motor leftMotor(2,3);

void loop() {
}

int main()
{
    init();
    while(true)
        loop();
    return 0;
}
