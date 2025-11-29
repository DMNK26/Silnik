#pragma once
#include "GameObject.h"

/// [lab4.1b] Wirtualne dziedziczenie, by uniknąć problemu diamentu
class UpdatableObject : virtual public GameObject {
public:
    virtual void update(float deltaTime) = 0;
};
