#pragma once
#include "GameObject.h"

///[lab4.1c] Rysowalny obiekt dziedziczący po klasie GameObject
class DrawableObject : virtual public GameObject {
public:
    /// Wirtualna metoda rysowania obiektu
    virtual void draw(sf::RenderWindow& window) = 0;
};
