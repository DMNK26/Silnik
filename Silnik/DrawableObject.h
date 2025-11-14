#pragma once
#include "GameObject.h"

//Lab4.1c
class DrawableObject : virtual public GameObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};
