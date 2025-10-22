#include "Point2D.h"
#include "PrimitiveRenderer.h"

// Konstruktor z opcjonalnymi współrzędnymi
Point2D::Point2D(float x, float y) : _x(x), _y(y) {}

float Point2D::getX() const { return _x; } // Zwraca współrzędną X punktu
float Point2D::getY() const { return _y; } // Zwraca współrzędną Y punktu

void Point2D::set(float x, float y) {
    _x = x; _y = y; // Ustawia współrzędne punktu
}

// Rysuje punkt za pomocą PrimitiveRenderer
void Point2D::draw(PrimitiveRenderer& renderer, sf::Color color) const {
    renderer.drawPoint(_x, _y, color);
}