#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab4.1e] Obiekt prostokąt dziedziczący po ShapeObject
class RectangleObject : public ShapeObject {
private:
    /// Obiekt prostokąta
    sf::RectangleShape _shape;

public:
    /// Konstruktor klasy RectangleObject
    RectangleObject(float x, float y, float width, float height, sf::Color color = sf::Color::White);

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
	/// Metoda rotacji
    void rotate(float angle) override;
    /// Metoda skalowania
    void scale(float sx, float sy) override;
    /// Metoda aktualizująca prostokąt
    void update(float dt) override;
};
