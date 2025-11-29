#include "EllipseObject.h"

//konstruktor elipsy
EllipseObject::EllipseObject(float x, float y, float rx, float ry, sf::Color color)
{
    _shape.setRadius(1.f); //promień
    _shape.setScale(rx, ry); //skala
    _shape.setFillColor(color); //kolor
    _shape.setOrigin(1.f, 1.f); //punkt odniesienia
    _shape.setPosition(x, y); //pozycja
}

//Rysowanie obiektu
void EllipseObject::draw(sf::RenderWindow& window) {
    window.draw(_shape); 
}

//Relatywne przesunięcie obiektu
void EllipseObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

//Rotacja
void EllipseObject::rotate(float a) {
    _shape.rotate(a);
}


//Skala
void EllipseObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

void EllipseObject::update(float dt)
{

}

