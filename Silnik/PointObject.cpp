#include "PointObject.h"

//LAB4.2A
///konstruktor punktu
PointObject::PointObject(float x, float y, float r, sf::Color color) {
    _shape.setRadius(r); //promień
    _shape.setFillColor(color); //kolor
    _shape.setOrigin(r, r); //punkt odniesienia
    _shape.setPosition(x, y); //pozycja
}

///Rysowanie obiektu
void PointObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

///Relatywne przesunięcie obiektu
void PointObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

///Rotacja
void PointObject::rotate(float angle) {
    _shape.rotate(angle);
}

///Skala
void PointObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}


/// Aktualizacja punktu
void PointObject::update(float dt)
{

}
