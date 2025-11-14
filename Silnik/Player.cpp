#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

Player::Player(float x, float y, float size, sf::Color color)
    : _speed(200.f), _rotationSpeed(120.f)
{
    _shape.setSize({ size, size });
    _shape.setOrigin(size / 2.f, size / 2.f);
    _shape.setFillColor(color);
    _shape.setPosition(x, y);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

void Player::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

void Player::rotate(float angle) {
    _shape.rotate(angle);
}

void Player::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

void Player::update(const sf::RenderWindow& window) {
    float dt = 1.f / 60.f; // możesz w przyszłości wprowadzić czasomierz z Engine
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= _speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += _speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= _speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += _speed * dt;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotate(-_rotationSpeed * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rotate(_rotationSpeed * dt);

    translate(movement.x, movement.y);

    // Opcjonalnie: podążanie za myszką
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        _shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}
