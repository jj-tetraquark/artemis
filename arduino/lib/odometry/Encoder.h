#ifndef BASE_ENCODER_H
#define BASE_ENCODER_H

class Encoder 
{
public:
    enum Direction { FORWARDS = 1, BACKWARDS = -1};
    virtual float RevolutionsPerSecond() = 0;
    virtual float GetFrequency() = 0;
    virtual Direction GetDirection() const = 0;

};

#endif /* end of include guard: BASE_ENCODER_H */
