#include "EllipseObject.h"

EllipseObject::EllipseObject(float x, float y, float rx, float ry, sf::Color color)
{
    _shape.setRadius(1.f);
    _shape.setScale(rx, ry);
    _shape.setFillColor(color);
    _shape.setOrigin(1.f, 1.f);
    _shape.setPosition(x, y);
}

void EllipseObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

void EllipseObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

void EllipseObject::rotate(float a) {
    _shape.rotate(a);
}

void EllipseObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

void EllipseObject::update(float dt)
{

}

