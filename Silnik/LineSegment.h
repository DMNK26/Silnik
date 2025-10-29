#pragma once
#include "Point2D.h"

/** [lab2.5] Klasa LineSegment */
class LineSegment {
private:
	Point2D _start, _end; // Punkty początkowy i końcowy odcinka
public:
	LineSegment(Point2D start, Point2D end); // Konstruktor z punktami początkowym i końcowym

	Point2D getStart() const; // Zwraca punkt początkowy odcinka
	Point2D getEnd() const; // Zwraca punkt końcowy odcinka
	void setStart(Point2D p); // Ustawia punkt początkowy odcinka
	void setEnd(Point2D p); // Ustawia punkt końcowy odcinka

	void draw(PrimitiveRenderer& renderer, bool incremental = false, sf::Color color = sf::Color::White) const; // Rysuje odcinek za pomocą PrimitiveRenderer
};