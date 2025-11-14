#include "RectangleObject.h"

RectangleObject::RectangleObject(float x, float y, float w, float h, sf::Color color) {
    _shape.setSize({ w, h });
    _shape.setFillColor(color);
    _shape.setOrigin(w / 2.f, h / 2.f);
    _shape.setPosition(x, y);
}

void RectangleObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

void RectangleObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

void RectangleObject::rotate(float angle) {
    _shape.rotate(angle);
}

void RectangleObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

void RectangleObject::update(float dt)
{

}