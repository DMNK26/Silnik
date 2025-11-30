#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

///[lab4.1e] Obiekt elipsy dziedziczący po ShapeObject
class EllipseObject : public ShapeObject {
private:
    /// Prywatny obiekt koła
    sf::CircleShape _shape;

public:
    /// Konstruktor klasy EllipseObject
    EllipseObject(float x, float y, float radiusX, float radiusY, sf::Color color = sf::Color::White);

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
    /// Metoda rotacji
    void rotate(float angle) override;
    /// Metoda skalowania
    void scale(float sx, float sy) override;
    /// Metoda aktualizująca elipse
    void update(float dt) override;
};
