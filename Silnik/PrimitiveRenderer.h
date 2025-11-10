#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Logger.h"
#include "Point2D.h"

/** Klasa odpowiedzialna za rysowanie prymitywów na oknie SFML */
class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);

	void drawPoint(float x, float y, sf::Color color = sf::Color::White);
	void drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White);
	void drawLineIncremental(sf::Vector2f p1, sf::Vector2f p2, sf::Color color); 
	void drawPolyline(const std::vector<Point2D>& points, sf::Color color = sf::Color::White, bool closed = false);
	
	void drawCircleSymmetry(sf::Vector2f center, float radius, sf::Color color = sf::Color::White); 
	void drawEllipseSymmetry(sf::Vector2f center, float a, float b, sf::Color color = sf::Color::White); 
	void drawPolygon(const std::vector<sf::Vector2f>& vertices, sf::Color color);
	void drawFilledPolygon(const std::vector<sf::Vector2f>& vertices, sf::Color color);
	void drawFilledCircle(sf::Vector2f center, float radius, sf::Color color = sf::Color::White); 
	
	void borderfill(sf::Vector2f seedPoint, sf::Color fillColor, sf::Color boundaryColor); 
	void floodfill(sf::Vector2f seedPoint, sf::Color fillColor); 
	
	
private:
	/** Referencja do okna SFML, na którym będą rysowane prymitywy */
	sf::RenderWindow& _window;
};