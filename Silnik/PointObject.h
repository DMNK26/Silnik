#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab 4.2A]
class PointObject : public ShapeObject {
private:
    /// komentarz
    sf::CircleShape _shape;

public:
    /// komentarz
    PointObject(float x, float y, float radius = 3.f, sf::Color color = sf::Color::White);

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
