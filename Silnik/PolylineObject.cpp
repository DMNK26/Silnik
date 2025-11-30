#include "PolylineObject.h"
#include <cmath>

///Konstruktor linii łamanej 
PolylineObject::PolylineObject(const std::vector<sf::Vector2f>& points, sf::Color color)
    : _vertices(sf::LineStrip), _originalPoints(points)
{
    if (_originalPoints.size() < 2) {
        _originalPoints = { {0,0}, {10,0} };
    }

    _origin = computeCentroid(_originalPoints);
    rebuildVertexArray();

    for (std::size_t i = 0; i < _vertices.getVertexCount(); i++)
        _vertices[i].color = color;
}

///Odbuduj tablice wierzchołków
void PolylineObject::rebuildVertexArray()
{
    _vertices.clear();
    _vertices.setPrimitiveType(sf::LineStrip);

    for (const auto& p : _originalPoints)
        _vertices.append(sf::Vertex(p, sf::Color::White));
}

///Oblicza środek geometryczny wszystkich punktów wektora
sf::Vector2f PolylineObject::computeCentroid(const std::vector<sf::Vector2f>& pts) const
{
    sf::Vector2f avg(0, 0);
    for (auto& p : pts) avg += p;
    return avg / (float)pts.size();
}

///Rysowanie obiektu
void PolylineObject::draw(sf::RenderWindow& window)
{
    window.draw(_vertices);
}

///Relatywne przesunięcie obiektu
void PolylineObject::translate(float dx, float dy)
{
    for (auto& p : _originalPoints) {
        p.x += dx;
        p.y += dy;
    }
    rebuildVertexArray();
}

///Rotacja
void PolylineObject::rotate(float angle)
{
    float rad = angle * 3.14159f / 180.f;

    for (auto& p : _originalPoints) {
        float x = p.x - _origin.x;
        float y = p.y - _origin.y;

        float xr = x * cos(rad) - y * sin(rad);
        float yr = x * sin(rad) + y * cos(rad);

        p.x = xr + _origin.x;
        p.y = yr + _origin.y;
    }
    rebuildVertexArray();
}

///Skala
void PolylineObject::scale(float sx, float sy)
{
    for (auto& p : _originalPoints) {
        p.x = _origin.x + (p.x - _origin.x) * sx;
        p.y = _origin.y + (p.y - _origin.y) * sy;
    }
    rebuildVertexArray();
}
/// Aktualizacja linii łamanej
void PolylineObject::update(float /*dt*/)
{
    
}

///Ustaw kolor
void PolylineObject::setColor(sf::Color color)
{
    for (std::size_t i = 0; i < _vertices.getVertexCount(); i++)
        _vertices[i].color = color;
}


///Dodaj punkt 
void PolylineObject::addPoint(const sf::Vector2f& p)
{
    _originalPoints.push_back(p);
    _origin = computeCentroid(_originalPoints);
    rebuildVertexArray();
}

///Zwraca ilość punktów(wierzchołków)
std::size_t PolylineObject::getPointCount() const
{
    return _originalPoints.size();
}
