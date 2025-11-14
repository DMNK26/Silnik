#include "CircleObject.h"

CircleObject::CircleObject(sf::Vector2f position,float radius, sf::Color color) {
	_shape = new sf::CircleShape(radius);
	_shape->setFillColor(color);
	_shape->setPosition(position);
}

void CircleObject::update(float deltaTime) {
	if (_shape)
		_shape->rotate(50.f * deltaTime);
}


