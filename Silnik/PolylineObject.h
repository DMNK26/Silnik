#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

///[lab4.1e] Obiekt linii łamanej dziedziczącej po ShapeObject
class PolylineObject : public ShapeObject {
public:
    /// Konstruktor z wektorem punktów (punkty w układzie okna)
    PolylineObject(const std::vector<sf::Vector2f>& points, sf::Color color = sf::Color::White);

    /// Konstruktor pomocniczy - lista inicjalizacyjna
    PolylineObject(std::initializer_list<sf::Vector2f> points,
        sf::Color color = sf::Color::White)
        : PolylineObject(std::vector<sf::Vector2f>(points), color) {
    }
    /// Destruktor
    virtual ~PolylineObject() = default;

    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;

    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;

    /// Metoda rotacji
    void rotate(float angle) override;

    /// Metoda skalowania
    void scale(float sx, float sy) override;

    /// Metoda aktualizująca linie łamaną
    void update(float dt) override;

    /// Ustawia kolor do wypełnienia
    void setColor(sf::Color color);

    /// Metoda dodaje punkt z którym reszta linii połączy się
    void addPoint(const sf::Vector2f& p);

    ///  Współrzędne wybranego punktu linii łamanej na podstawie indeksu
    std::size_t getPointCount() const;

private:
    /// Tablica wierzchołków używana do rysowania prymitywu
    sf::VertexArray _vertices;

    /// Oryginalne punkty prymitywu przed transformacjami
    std::vector<sf::Vector2f> _originalPoints;

    /// Punkt odniesienia używany jako środek transformacji
    sf::Vector2f _origin;

    ///  Oblicza centroid przekazanej listy punktów
    sf::Vector2f computeCentroid(const std::vector<sf::Vector2f>& pts) const;
    
    
    /// Buduje ponownie tablicę wierzchołków po zmianach geometrii
    void rebuildVertexArray();
};
