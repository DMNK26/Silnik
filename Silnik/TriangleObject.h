#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab4.1e] Obiekt trójkąta dziedziczący po ShapeObject
class TriangleObject : public ShapeObject {
private:
    sf::ConvexShape _shape;

public:
	/// Konstruktor klasy TriangleObject
    TriangleObject(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color = sf::Color::White);

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
    /// Metoda rotacji
    void rotate(float angle) override;
    /// Metoda skalowania
    void scale(float sx, float sy) override;
    /// Metoda aktualizująca trójkąt
    void update(float dt) override;
};
