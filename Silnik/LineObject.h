#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab 4.2b] Obiekt linii dziedziczacy po ShapeObject
class LineObject : public ShapeObject {
private:
    /// Tablica przechowująca dwa punkty linii
    sf::VertexArray _line;
    /// Dwie 2-wymiarowe współrzędne (x,y) reprezentujące punkty końcowe odcinka.
    sf::Vector2f _p1, _p2;

public:
    /// Konstruktor klasy LineObject
    LineObject(sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White);

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
    /// Metoda rotacji
    void rotate(float angle) override;
    /// Metoda skalowania
    void scale(float sx, float sy) override;
    /// Metoda aktualizująca linie
    void update(float dt) override;
};
