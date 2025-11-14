#pragma once
#include "GameObject.h"

//Lab4.1d
class TransformableObject : virtual public GameObject {
public:
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factorX, float factorY) = 0;
};
