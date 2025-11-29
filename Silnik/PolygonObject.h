#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

//lab4.1e Obiekt wielokątu dziedziczący po ShapeObject
class PolygonObject : public ShapeObject {
public:
    // Konstruktor z wektorem punktów (punkty w układzie okna)
    PolygonObject(const std::vector<sf::Vector2f>& points, sf::Color fillColor = sf::Color::White);

    // Konstruktor pomocniczy - lista inicjalizacyjna
    PolygonObject(std::initializer_list<sf::Vector2f> points, sf::Color fillColor = sf::Color::White)
        : PolygonObject(std::vector<sf::Vector2f>(points), fillColor) {
    }

    virtual ~PolygonObject() = default;

    // Drawable
    void draw(sf::RenderWindow& window) override;

    // Transformable interface
    void translate(float dx, float dy) override;
    void rotate(float angle) override;       // degrees
    void scale(float sx, float sy) override; // relative scale

    // Updatable (może zostać puste)
    void update(float dt) override;

    // dodatkowe przydatne metody
    void setFillColor(const sf::Color& color);
    void setOutline(float thickness, const sf::Color& color);
    std::size_t getPointCount() const;
    sf::Vector2f getPoint(std::size_t idx) const;

private:
    sf::ConvexShape _shape;
    std::vector<sf::Vector2f> _originalPoints; // przydatne, jeśli chcesz odtwarzać/skalować względem centroidu

    // oblicza centroid (środek ciężkości) wielokąta (wspiera także nieregularne)
    sf::Vector2f computeCentroid(const std::vector<sf::Vector2f>& pts) const;

    // ustawia origin na centroid i aktualizuje pozycję/pointy
    void updateShapeFromPoints();
};
