#include "LineSegment.h"
#include "PrimitiveRenderer.h"
#include <cmath>

/** [lab2.5] implementacja klasy LineSegment */

/** Konstruktor z punktami początkowym i końcowym*/
LineSegment::LineSegment(Point2D start, Point2D end)
    : _start(start), _end(end) {
}
/** Zwraca punkt początkowy odcinka */
Point2D LineSegment::getStart() const { return _start; }
/** Zwraca punkt końcowy odcinka*/
Point2D LineSegment::getEnd() const { return _end; } 
/** Ustawia punkt początkowy odcinka*/
void LineSegment::setStart(Point2D p) { _start = p; }
/** Ustawia punkt końcowy odcinka*/
void LineSegment::setEnd(Point2D p) { _end = p; } 

/** Rysuje odcinek za pomocą PrimitiveRenderer*/
void LineSegment::draw(PrimitiveRenderer& renderer, bool incremental, sf::Color color) const {
	if (incremental) // Rysowanie metodą przyrostową
        renderer.drawLineIncremental(
            { _start.getX(), _start.getY() },
            { _end.getX(), _end.getY() },
            color
        );
	else // Rysowanie standardową metodą
        renderer.drawLine(
            { _start.getX(), _start.getY() },
            { _end.getX(), _end.getY() },
            color
        );
}