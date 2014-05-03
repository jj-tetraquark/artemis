#ifndef CONFIG_H
#define CONFIG_H

namespace Config {

struct PID {
    constexpr static float K_Proportional = 1.0;
    constexpr static float K_Differential = 0.1;
    constexpr static float K_Integral     = 0.1;
};

};


#endif /* end of include guard: CONFIG_H */
