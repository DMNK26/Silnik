#include "TriangleObject.h"

TriangleObject::TriangleObject(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color) {
    _shape.setPointCount(3);
    _shape.setPoint(0, p1);
    _shape.setPoint(1, p2);
    _shape.setPoint(2, p3);
    _shape.setFillColor(color);

    sf::Vector2f center = (p1 + p2 + p3) / 3.f;
    _shape.setOrigin(center);
    _shape.setPosition(center);
}

void TriangleObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

void TriangleObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

void TriangleObject::rotate(float angle) {
    _shape.rotate(angle);
}

void TriangleObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}
void TriangleObject::update(float dt)
{

}

