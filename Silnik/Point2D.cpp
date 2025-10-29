#include "Point2D.h"
#include "PrimitiveRenderer.h"

/** [lab2.4] implementacja klasy Point2D*/

/**  Konstruktor z opcjonalnymi współrzędnymi */
Point2D::Point2D(float x, float y) : _x(x), _y(y) {}

/** Zwraca współrzędną X punktu*/
float Point2D::getX() const { return _x; } 
/** Zwraca współrzędną Y punktu*/
float Point2D::getY() const { return _y; }

/** Ustawia współrzędne punktu*/
void Point2D::set(float x, float y) {
    _x = x; _y = y; 
}

/**  Rysuje punkt za pomocą PrimitiveRenderer */
void Point2D::draw(PrimitiveRenderer& renderer, sf::Color color) const {
    renderer.drawPoint(_x, _y, color);
}