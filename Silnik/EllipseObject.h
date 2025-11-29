#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

//lab4.1e Obiekt elipsy dziedziczący po ShapeObject
class EllipseObject : public ShapeObject {
private:
    sf::CircleShape _shape;

public:
    EllipseObject(float x, float y, float radiusX, float radiusY, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void update(float dt) override;
};
