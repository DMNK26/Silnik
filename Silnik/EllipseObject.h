#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

///[lab4.1e] Obiekt elipsy dziedziczący po ShapeObject
class EllipseObject : public ShapeObject {
private:
    /// komentarz
    sf::CircleShape _shape;

public:
    /// komentarz
    EllipseObject(float x, float y, float radiusX, float radiusY, sf::Color color = sf::Color::White);

    /// komentarz
    void draw(sf::RenderWindow& window) override;
    /// komentarz
    void translate(float dx, float dy) override;
    /// komentarz
    void rotate(float angle) override;
    /// komentarz
    void scale(float sx, float sy) override;
    /// komentarz
    void update(float dt) override;
};
