#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab4.2a] Obiekt punktu dziedziczący po ShapeObject
class PointObject : public ShapeObject {
private:
    /// Prywatny obiekt koła
    sf::CircleShape _shape;

public:
    /// Konstruktor klasy PointObject
    PointObject(float x, float y, float radius = 3.f, sf::Color color = sf::Color::White);

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
    /// Metoda rotacji
    void rotate(float angle) override;
    /// Metoda skalowania
    void scale(float sx, float sy) override;
    /// Metoda aktualizująca punkt
    void update(float dt) override;
};
