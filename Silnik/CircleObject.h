#pragma once
#include "ShapeObject.h"

//lab4.1e Obiekt koła dziedziczący po ShapeObject
class CircleObject : public ShapeObject {
public:
    CircleObject(sf::Vector2f position, float radius, sf::Color color);
    void update(float deltaTime) override;
};