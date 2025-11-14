#include "PointObject.h"

//LAB4.2A
PointObject::PointObject(float x, float y, float r, sf::Color color) {
    _shape.setRadius(r);
    _shape.setFillColor(color);
    _shape.setOrigin(r, r);
    _shape.setPosition(x, y);
}

void PointObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

void PointObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

void PointObject::rotate(float angle) {
    _shape.rotate(angle);
}

void PointObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

void PointObject::update(float dt)
{

}
