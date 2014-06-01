#ifndef CONFIG_H
#define CONFIG_H

namespace Config {

struct PID {
    constexpr static float K_PROPORTIONAL = 1.0;
    constexpr static float K_DIFFERENTIAL = 0.1;
    constexpr static float K_INTEGRAL     = 0.1;
};

struct Pins {
    constexpr static int LEFT_MOTOR_DIRECTION   = 4;
    constexpr static int LEFT_MOTOR_SPEED       = 5;
    constexpr static int RIGHT_MOTOR_DIRECTION  = 7;
    constexpr static int RIGHT_MOTOR_SPEED      = 6;
    constexpr static int LEFT_ENCODER_A         = 8;
    constexpr static int LEFT_ENCODER_B         = 9;
    constexpr static int RIGHT_ENCODER_A        = 10;
    constexpr static int RIGHT_ENCODER_B        = 11;
};

};


#endif /* end of include guard: CONFIG_H */
