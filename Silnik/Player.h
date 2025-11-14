#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

class Player : public ShapeObject {
private:
    sf::RectangleShape _shape;
    float _speed;
    float _rotationSpeed;

public:
    Player(float x = 100.f, float y = 100.f, float size = 40.f, sf::Color color = sf::Color::Blue);

    // dziedziczone wirtualne metody
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    // aktualizacja stanu gracza (wejście)
    void update(const sf::RenderWindow& window);

    // getter pozycji
    sf::Vector2f getPosition() const { return _shape.getPosition(); }
};
