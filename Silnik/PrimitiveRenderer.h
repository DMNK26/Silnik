#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Logger.h"
#include "Point2D.h"

/// Klasa odpowiedzialna za rysowanie prymitywów na oknie SFML 
class PrimitiveRenderer {
public:
	/// Przechowywanie referencji do okna, na którym będą rysowane prymitywy 
    PrimitiveRenderer(sf::RenderWindow& window);

	/// Rysowanie pojedynczego punktu o danych współrzędnych i kolorze 
	void drawPoint(float x, float y, sf::Color color = sf::Color::White);
	/// Rysowanie linii między dwoma punktami o danym kolorze 
	void drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White);
	/// [lab2.3] Rysowanie linii między dwoma punktami metodą przyrostową (Bresenhama)  
	void drawLineIncremental(sf::Vector2f p1, sf::Vector2f p2, sf::Color color); 
	/// [lab2.6] Rysowanie polilinii z podanej listy punktów, opcjonalnie zamkniętej  
	void drawPolyline(const std::vector<Point2D>& points, sf::Color color = sf::Color::White, bool closed = false);
	/// [lab3.1] Rysowanie okregu 8-krotną symetrią  
	void drawCircleSymmetry(sf::Vector2f center, float radius, sf::Color color = sf::Color::White); 
	/// [lab3.2] Rysowanie elipsy z wykorzystaniem 8-krotniej symetrii 
	void drawEllipseSymmetry(sf::Vector2f center, float a, float b, sf::Color color = sf::Color::White); 
	/// [lab3.3] Rysowanie wielokąta z kontrolą przecinania się odcinków  
	void drawPolygon(const std::vector<sf::Vector2f>& vertices, sf::Color color);
	/// [lab3.4] Rysowanie wypełnionego wielokąta 
	void drawFilledPolygon(const std::vector<sf::Vector2f>& vertices, sf::Color color);
	/// [lab3.4] Rysowanie wypełnionego koła  
	void drawFilledCircle(sf::Vector2f center, float radius, sf::Color color = sf::Color::White); 
	
	///  [lab3.5] Wypełnianie obszaru metodą borderfill 
	void borderfill(sf::Vector2f seedPoint, sf::Color fillColor, sf::Color boundaryColor); 
	/// [lab3.5] Wypełnianie obszaru metodą floodfill 
	void floodfill(sf::Vector2f seedPoint, sf::Color fillColor); 
	
	
private:
	/** Referencja do okna SFML, na którym będą rysowane prymitywy */
	sf::RenderWindow& _window;
};