#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

//LAB4.2A
class PointObject : public ShapeObject {
private:
    sf::CircleShape _shape;

public:
    PointObject(float x, float y, float radius = 3.f, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void update(float dt) override;
};
