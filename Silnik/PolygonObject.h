#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

/// [lab4.1e] Obiekt wielokątu dziedziczący po ShapeObject
class PolygonObject : public ShapeObject {
public:
    /// Konstruktor z wektorem punktów (punkty w układzie okna)
    PolygonObject(const std::vector<sf::Vector2f>& points, sf::Color fillColor = sf::Color::White);

    /// Konstruktor pomocniczy - lista inicjalizacyjna
    PolygonObject(std::initializer_list<sf::Vector2f> points, sf::Color fillColor = sf::Color::White)
        : PolygonObject(std::vector<sf::Vector2f>(points), fillColor) {
    }
    /// Destruktor klasy PolygonObject
    virtual ~PolygonObject() = default;

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;

    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
    /// Metoda rotacji
    void rotate(float angle) override;   
    ///  Metoda skalowania
    void scale(float sx, float sy) override; 

    /// Metoda aktualizująca wielokąt
    void update(float dt) override;

    /// Ustawia kolor do wypełnienia
    void setFillColor(const sf::Color& color);

    /// Ustawia kolor obramowania
    void setOutline(float thickness, const sf::Color& color);

    /// Ilość wierzchołków
    std::size_t getPointCount() const;

    /// Współrzędne wybranego wierzchołka wielokąta na podstawie indeksu
    sf::Vector2f getPoint(std::size_t idx) const;

private:
    sf::ConvexShape _shape;
    std::vector<sf::Vector2f> _originalPoints;

    /// Oblicza centroid (środek ciężkości) wielokąta
    sf::Vector2f computeCentroid(const std::vector<sf::Vector2f>& pts) const;

    /// Ustawia origin na centroid i aktualizuje pozycję/wierzchołki
    void updateShapeFromPoints();
};
