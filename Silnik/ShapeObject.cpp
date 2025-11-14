#include "ShapeObject.h"


    ShapeObject::~ShapeObject() {
        delete _shape;
    }

    void ShapeObject::draw(sf::RenderWindow& window) {
        if (_shape)
            window.draw(*_shape);
    }

    void ShapeObject::translate(float dx, float dy) {
        if (_shape)
            _shape->move(dx, dy);
    }

    void ShapeObject::rotate(float angle) {
        if (_shape)
            _shape->rotate(angle);
    }

    void ShapeObject::scale(float factorX, float factorY) {
        if (_shape)
            _shape->scale(factorX, factorY);
    }

    void ShapeObject::update(float dt)
    {

    }
