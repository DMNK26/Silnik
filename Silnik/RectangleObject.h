#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab4.1e] Obiekt prostokąt dziedziczący po ShapeObject
class RectangleObject : public ShapeObject {
private:
    /// komentarz
    sf::RectangleShape _shape;

public:
    /// komentarz
    RectangleObject(float x, float y, float width, float height, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
	/// komentarz
    void rotate(float angle) override;
    /// komentarz
    void scale(float sx, float sy) override;
    void update(float dt) override;
};
