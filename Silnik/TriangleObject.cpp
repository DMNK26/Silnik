#include "TriangleObject.h"

///Konstruktor trójkąta
TriangleObject::TriangleObject(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color) {
    _shape.setPointCount(3); //ilość wierzchołków(tutaj na sztywno 3 ponieważ to trójkąt)
    _shape.setPoint(0, p1);//ustaw punkt 1 wierzchołka
    _shape.setPoint(1, p2);//ustaw punkt 2 wierzchołka
    _shape.setPoint(2, p3);//ustaw punkt 3 wierzchołka
    _shape.setFillColor(color); // kolor

    sf::Vector2f center = (p1 + p2 + p3) / 3.f; //oblicza środek trójkąta
    _shape.setOrigin(center);//punkt odniesienia
    _shape.setPosition(center);//pozycja
}

///Rysowanie obiektu
void TriangleObject::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

///Relatywne przesunięcie obiektu
void TriangleObject::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

///Rotacja
void TriangleObject::rotate(float angle) {
    _shape.rotate(angle);
}

///Skala
void TriangleObject::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}


/// Aktualizacja trójkąta
void TriangleObject::update(float dt)
{

}

