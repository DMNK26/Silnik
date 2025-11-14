#pragma once
#include "ShapeObject.h"

class CircleObject : public ShapeObject {
public:
    CircleObject(sf::Vector2f position, float radius, sf::Color color);
    void update(float deltaTime) override;
};