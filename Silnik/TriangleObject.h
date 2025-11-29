#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab4.1e] Obiekt trójkąta dziedziczący po ShapeObject
class TriangleObject : public ShapeObject {
private:
    sf::ConvexShape _shape;

public:
	/// komentarz
    TriangleObject(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void update(float dt) override;
};
