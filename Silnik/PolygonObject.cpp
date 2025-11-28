#include "PolygonObject.h"
#include <numeric>
#include <cmath>

PolygonObject::PolygonObject(const std::vector<sf::Vector2f>& points, sf::Color fillColor)
    : _originalPoints(points)
{
    if (_originalPoints.empty()) {
        // safety: utwórz mały trójkąt zamiast pustego kształtu
        _originalPoints = { {0.f,0.f}, {10.f,0.f}, {5.f,10.f} };
    }
    updateShapeFromPoints();
    _shape.setFillColor(fillColor);
}

void PolygonObject::updateShapeFromPoints()
{
    // ustaw punkty w m_shape
    _shape.setPointCount(_originalPoints.size());
    for (std::size_t i = 0; i < _originalPoints.size(); ++i) {
        _shape.setPoint(i, _originalPoints[i]);
    }

    // oblicz centroid i ustaw origin oraz pozycję
    sf::Vector2f centroid = computeCentroid(_originalPoints);

    // ustaw origin tak, żeby transformacje były wykonywane względem centroidu
    _shape.setOrigin(centroid);

    // pozycję ustawiamy na centroid (shape interpretuje punkty względem pozycji + origin)
    _shape.setPosition(centroid);
}

sf::Vector2f PolygonObject::computeCentroid(const std::vector<sf::Vector2f>& pts) const
{
    // centroid dla wielokąta prostego (Shoelace formula)
    // jeśli wielokąt jest zbyt mały lub niepoprawny, zwracamy średnią arytmetyczną punktów
    float area = 0.f;
    float cx = 0.f;
    float cy = 0.f;
    const std::size_t n = pts.size();

    if (n < 3) {
        // fallback: średnia punktów
        sf::Vector2f avg(0.f, 0.f);
        for (const auto& p : pts) avg += p;
        return avg / static_cast<float>(std::max<std::size_t>(1, n));
    }

    for (std::size_t i = 0; i < n; ++i) {
        const sf::Vector2f& p0 = pts[i];
        const sf::Vector2f& p1 = pts[(i + 1) % n];
        float cross = p0.x * p1.y - p1.x * p0.y;
        area += cross;
        cx += (p0.x + p1.x) * cross;
        cy += (p0.y + p1.y) * cross;
    }

    area *= 0.5f;
    if (std::fabs(area) < 1e-6f) {
        // degenarate polygon -> fallback na średnią
        sf::Vector2f avg(0.f, 0.f);
        for (const auto& p : pts) avg += p;
        return avg / static_cast<float>(n);
    }

    cx /= (6.f * area);
    cy /= (6.f * area);
    return sf::Vector2f(cx, cy);
}

void PolygonObject::draw(sf::RenderWindow& window)
{
    window.draw(_shape);
}

void PolygonObject::translate(float dx, float dy)
{
    _shape.move(dx, dy);
    // przesuwając shape nie musimy zmieniać m_originalPoints; pozycja SFML jest niezależna
}

void PolygonObject::rotate(float angle)
{
    _shape.rotate(angle);
}

void PolygonObject::scale(float sx, float sy)
{
    _shape.scale(sx, sy);
}

void PolygonObject::update(float /*dt*/)
{
    // domyślnie brak logiki aktualizacyjnej
}

void PolygonObject::setFillColor(const sf::Color& color)
{
    _shape.setFillColor(color);
}

void PolygonObject::setOutline(float thickness, const sf::Color& color)
{
    _shape.setOutlineThickness(thickness);
    _shape.setOutlineColor(color);
}

std::size_t PolygonObject::getPointCount() const
{
    return _shape.getPointCount();
}

sf::Vector2f PolygonObject::getPoint(std::size_t idx) const
{
    if (idx < _shape.getPointCount())
        return _shape.getPoint(idx);
    return {};
}
