#include "CircleObject.h"

//lab4.1e Konstruktor koła
CircleObject::CircleObject(sf::Vector2f position,float radius, sf::Color color) {
	_shape = new sf::CircleShape(radius); //promień
	_shape->setFillColor(color); //kolor
	_shape->setPosition(position); //pozycja
}

void CircleObject::update(float deltaTime) {
	if (_shape)
		_shape->rotate(50.f * deltaTime); //rotacja
}


