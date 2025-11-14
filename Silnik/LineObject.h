#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

//LAB4.2B
class LineObject : public ShapeObject {
private:
    sf::VertexArray _line;
    sf::Vector2f _p1, _p2;

public:
    LineObject(sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void update(float dt) override;
};
