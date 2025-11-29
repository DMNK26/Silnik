#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab 4.2b] Obiekt linii dziedziczacy po ShapeObject
class LineObject : public ShapeObject {
private:
    /// komentarz
    sf::VertexArray _line;
    /// komentarz
    sf::Vector2f _p1, _p2;

public:
    /// komentarz
    LineObject(sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White);

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
