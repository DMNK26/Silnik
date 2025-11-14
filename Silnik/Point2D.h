#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeObject.h"

/** Deklaracja wprzód klasy PrimitiveRenderer */
class PrimitiveRenderer;

/** Klasa reprezentująca punkt w przestrzeni 2D */
class Point2D {
private:
    float _x, _y; 
public:
	Point2D(float x = 0, float y = 0); // Konstruktor z opcjonalnymi współrzędnymi

	float getX() const; // Zwraca współrzędną X punktu
	float getY() const; // Zwraca współrzędną Y punktu
	void set(float x, float y); // Ustawia współrzędne punktu

	void draw(PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) const; // Rysuje punkt za pomocą PrimitiveRenderer
};