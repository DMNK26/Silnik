#include "ShapeObject.h"

//Konstruktor ShapeObject
ShapeObject::~ShapeObject() {
    delete _shape;
}

//Rysuj
void ShapeObject::draw(sf::RenderWindow& window) {
    if (_shape)
        window.draw(*_shape);
}

//Relatywne przesunięcie obiektu
void ShapeObject::translate(float dx, float dy) {
    if (_shape)
        _shape->move(dx, dy);
}

//Rotacja
void ShapeObject::rotate(float angle) {
    if (_shape)
        _shape->rotate(angle);
}

//Skala
void ShapeObject::scale(float factorX, float factorY) {
    if (_shape)
        _shape->scale(factorX, factorY);
}

//Aktualizacja figury
void ShapeObject::update(float dt)
{ }
