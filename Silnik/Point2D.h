#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeObject.h"

/// Deklaracja wprzód klasy PrimitiveRenderer
class PrimitiveRenderer;

///[lab2.4]  Klasa reprezentująca punkt w przestrzeni 2D 
class Point2D {
private:
	/// Współrzędne
    float _x, _y; 
public:
	/// Konstruktor z opcjonalnymi współrzędnymi
	Point2D(float x = 0, float y = 0); 
	/// Zwraca współrzędną X punktu
	float getX() const;
	/// Zwraca współrzędną Y punktu
	float getY() const;
	/// Ustawia współrzędne punktu
	void set(float x, float y); 
	/// Rysuje punkt za pomocą PrimitiveRenderer 
	void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) const; // Rysuje punkt za pomocą PrimitiveRenderer
};