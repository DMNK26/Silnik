#pragma once
#include "GameObject.h"

/// [lab4.1d]
class TransformableObject : virtual public GameObject {
public:
    /// komentarz
    virtual void translate(float dx, float dy) = 0;
    /// komentarz
    virtual void rotate(float angle) = 0;
    /// komentarz
    virtual void scale(float factorX, float factorY) = 0;
};
