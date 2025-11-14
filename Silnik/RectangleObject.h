#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

class RectangleObject : public ShapeObject {
private:
    sf::RectangleShape _shape;

public:
    RectangleObject(float x, float y, float width, float height, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void update(float dt) override;
};
