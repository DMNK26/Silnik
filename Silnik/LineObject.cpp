#include "LineObject.h"
#include <cmath>

//LAB4.2B
//konstruktor linii 
LineObject::LineObject(sf::Vector2f p1, sf::Vector2f p2, sf::Color color)
    : _p1(p1), _p2(p2)
{
    _line.setPrimitiveType(sf::Lines);
    _line.resize(2);
    _line[0].position = p1; //Punkt początkowy
    _line[1].position = p2; //Punkt końcowy
    _line[0].color = color;
    _line[1].color = color;
}

//Rysowanie obiektu
void LineObject::draw(sf::RenderWindow& window) {
    window.draw(_line);
}

//Relatywne przesunięcie obiektu
void LineObject::translate(float dx, float dy) {
    _p1.x += dx; _p1.y += dy;
    _p2.x += dx; _p2.y += dy;
    _line[0].position = _p1;
    _line[1].position = _p2;
}

//Rotacja
void LineObject::rotate(float angle) {
    float rad = angle * 3.14159265f / 180.f;
    sf::Vector2f c = { (_p1.x + _p2.x) / 2.f, (_p1.y + _p2.y) / 2.f };

    auto rotatePoint = [&](sf::Vector2f p) {
        float x = std::cos(rad) * (p.x - c.x) - std::sin(rad) * (p.y - c.y) + c.x;
        float y = std::sin(rad) * (p.x - c.x) + std::cos(rad) * (p.y - c.y) + c.y;
        return sf::Vector2f(x, y);
        };

    _p1 = rotatePoint(_p1);
    _p2 = rotatePoint(_p2);

    _line[0].position = _p1;
    _line[1].position = _p2;
}

//Skala
void LineObject::scale(float sx, float sy) {
    sf::Vector2f c = { (_p1.x + _p2.x) / 2.f, (_p1.y + _p2.y) / 2.f };

    auto scalePoint = [&](sf::Vector2f p) {
        return sf::Vector2f(
            c.x + (p.x - c.x) * sx,
            c.y + (p.y - c.y) * sy
        );
        };

    _p1 = scalePoint(_p1);
    _p2 = scalePoint(_p2);

    _line[0].position = _p1;
    _line[1].position = _p2;
}

void LineObject::update(float dt)
{

}
