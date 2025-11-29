#pragma once
#include "GameObject.h"

///[lab4.1c] rysowalny obiekt
class DrawableObject : virtual public GameObject {
public:
    /// komentarz
    virtual void draw(sf::RenderWindow& window) = 0;
};
