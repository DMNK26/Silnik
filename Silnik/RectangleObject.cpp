#include "RectangleObject.h"

///Kontruktor prostokąta
RectangleObject::RectangleObject(float x, float y, float w, float h, sf::Color color) {
    _shape.setSize({ w, h }); //ustala w - szerokość, h - wysokość
    _shape.setFillColor(color); //kolor
    _shape.setOrigin(w / 2.f, h / 2.f); //punkt odniesienia
    _shape.setPosition(x, y); //pozycja
}

///Rysowanie obiektu
void RectangleObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

///Relatywne przesunięcie obiektu
void RectangleObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

///Rotacja
void RectangleObject::rotate(float angle) {
    _shape.rotate(angle);
}

///Skala
void RectangleObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

///Aktualizacja prostokąta
void RectangleObject::update(float dt)
{

}