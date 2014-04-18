#ifndef BASE_ENCODER_H
#define BASE_ENCODER_H

class Encoder 
{
public:
    enum class Direction { FORWARDS, BACKWARDS };
    virtual float RevolutionsPerSecond() const = 0;
    virtual Direction GetDirection() const = 0;

};

#endif /* end of include guard: BASE_ENCODER_H */
