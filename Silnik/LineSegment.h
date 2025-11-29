#pragma once
#include "Point2D.h"
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

/// [lab2.5] Klasa LineSegment 
class LineSegment {
private:
	/// Punkty początkowy i końcowy odcinka
	Point2D _start, _end; 
public:
	/// Konstruktor z punktami początkowym i końcowym
	LineSegment(Point2D start, Point2D end); 
	/// Zwraca punkt początkowy odcinka
	Point2D getStart() const; 
	/// Zwraca punkt końcowy odcinka
	Point2D getEnd() const; 
	/// Ustawia punkt początkowy odcinka
	void setStart(Point2D p); 
	/// Ustawia punkt końcowy odcinka
	void setEnd(Point2D p); 
	/// komentarz
	void draw(PrimitiveRenderer& renderer, bool incremental = false, sf::Color color = sf::Color::White) const; // Rysuje odcinek za pomocą PrimitiveRenderer
};
