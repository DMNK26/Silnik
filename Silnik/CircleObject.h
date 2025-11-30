#pragma once
#include "ShapeObject.h"

///[lab4.1e] Obiekt koła dziedziczący po ShapeObject
class CircleObject : public ShapeObject {
public:
    /// Konstruktor klasy CircleObject
    CircleObject(sf::Vector2f position, float radius, sf::Color color);

    /// Metoda aktualizująca koło 
    void update(float deltaTime) override;
};