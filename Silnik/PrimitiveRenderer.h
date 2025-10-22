#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Logger.h"
#include "Point2D.h"

// Klasa odpowiedzialna za rysowanie prymitywów na oknie SFML
class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);

	void drawPoint(float x, float y, sf::Color color = sf::Color::White); // Rysowanie pojedynczego punktu o danych współrzędnych i kolorze
	void drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White); // Rysowanie linii między dwoma punktami o danym kolorze
	void drawRectangle(sf::FloatRect rect, sf::Color color = sf::Color::White); // Rysowanie prostokąta o podanym prostokątnym obszarze i kolorze
	void drawCircle(sf::Vector2f center, float radius, sf::Color color = sf::Color::White); // Rysowanie koła o podanym środku, promieniu i kolorze
	void drawLineIncremental(sf::Vector2f p1, sf::Vector2f p2, sf::Color color); // Rysowanie linii między dwoma punktami metodą przyrostową (Bresenhama)
	void drawPolyline(const std::vector<Point2D>& points, sf::Color color = sf::Color::White, bool closed = false); // Rysowanie polilinii łączącej podane punkty

private:
	sf::RenderWindow& _window; // Referencja do okna SFML, na którym będą rysowane prymitywy
};