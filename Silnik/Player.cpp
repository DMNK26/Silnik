// CAŁE DO ZAKOMENTOWANIA DO RYSOWANIA KSZTAŁTÓW
#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <filesystem>

// [Lab 5] Implementacja klasy Player
Player::Player(float x, float y, float size)
{
    animationFPS = 10.f;

    for (auto& vec : textures)
        vec.resize(framesPerDir);
    // Nazwy plików dla każdej klatki animacji w każdym kierunku
    const std::array<std::array<std::string, 3>, 4> files {{
        { "player_down_1.png", "player_down_2.png", "player_down_3.png" },
        { "player_left_1.png", "player_left_2.png", "player_left_3.png" },
        { "player_right_1.png", "player_right_2.png", "player_right_3.png" },
        { "player_up_1.png", "player_up_2.png", "player_up_3.png" }
    }};
    // Ładowanie tekstur
    for (int dir = 0; dir < 4; ++dir) {
        for (int frame = 0; frame < framesPerDir; ++frame) {
            std::string path = "assets/" + files[dir][frame];
            if (!loadFrame(path, static_cast<Direction>(dir), frame)) {
                std::cout << "[Player] ERROR loading: " << path << "\n";
            }
        }
    }

    applyCurrentFrame();
    getSprite().setPosition(x, y);
    getSprite().setScale(size / frameWidth, size / frameHeight);
}
// Ładuje pojedynczą klatkę animacji z pliku
bool Player::loadFrame(const std::string& path, Direction dir, int frameIndex) {
    auto tex = std::make_shared<sf::Texture>();

    if (!tex->loadFromFile(path)) {
        std::cout << "[Player] Could not load: " << path << "\n";
        return false;
    }

    textures[dir][frameIndex] = tex;
    return true;
}
// Zastosowuje aktualną klatkę animacji do sprite'a
void Player::applyCurrentFrame() {
    auto& tex = textures[currentDirection][currentFrame];
    if (tex)
        sprite.setTexture(*tex);

    sprite.setOrigin(frameWidth / 2.f, frameHeight / 2.f);
}
// Rysuje gracza na oknie
void Player::draw(sf::RenderWindow& window) {
    window.draw(getSprite());
}
// Przesuwa gracza o (dx, dy)
void Player::translate(float dx, float dy) {
    getSprite().move(dx, dy);
}
// Obraca gracza o kąt angle
void Player::rotate(float angle) {
    getSprite().rotate(angle);
}
// Skaluje gracza o (sx, sy)
void Player::scale(float sx, float sy) {
    getSprite().scale(sx, sy);
}
// Aktualizuje stan gracza na podstawie wejścia użytkownika
void Player::update(const sf::RenderWindow& window) {
    float dt = 1.f / 60.f;

    sf::Vector2f movement(0, 0);
    bool moved = false;
    Direction newDir = currentDirection;

    // sterowanie
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= _speed * dt;
        newDir = Up;
        moved = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += _speed * dt;
        newDir = Down;
        moved = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= _speed * dt;
        newDir = Left;
        moved = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += _speed * dt;
        newDir = Right;
        moved = true;
    }

    translate(movement.x, movement.y);

    isMoving = moved;

    if (newDir != currentDirection) {
        currentDirection = newDir;
        currentFrame = 1;
        timeAccumulator = 0;
        applyCurrentFrame();
    }

    if (isMoving) {
        timeAccumulator += dt;
        if (timeAccumulator >= 1.f / animationFPS) {
            timeAccumulator = 0;

            if (currentFrame == 1) currentFrame = 2;
            else if (currentFrame == 2) currentFrame = 0;
            else currentFrame = 1;

            applyCurrentFrame();
        }
    }
    else {
        if (currentFrame != 1) {
            currentFrame = 1;
            applyCurrentFrame();
        }
    }
}


// CAŁE DO ODKOMENTOWANIA DO RYSOWANIA KSZTAŁTÓW
// #include "Player.h"
// #include <SFML/Window/Keyboard.hpp>
// #include <SFML/Window/Mouse.hpp>
//
// Player::Player(float x, float y, float size, sf::Color color)
//     : _speed(200.f), _rotationSpeed(120.f)
// {
//     _shape.setSize({ size, size });
//     _shape.setOrigin(size / 2.f, size / 2.f);
//     _shape.setFillColor(color);
//     _shape.setPosition(x, y);
// }
//
// void Player::draw(sf::RenderWindow& window) {
//     window.draw(_shape);
// }
//
// void Player::translate(float dx, float dy) {
//     _shape.move(dx, dy);
// }
//
// void Player::rotate(float angle) {
//     _shape.rotate(angle);
// }
//
// void Player::scale(float sx, float sy) {
//     _shape.scale(sx, sy);
// }
//
// void Player::update(const sf::RenderWindow& window) {
//     float dt = 1.f / 60.f; // możesz w przyszłości wprowadzić czasomierz z Engine
//     sf::Vector2f movement(0.f, 0.f);
//
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= _speed * dt;
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += _speed * dt;
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= _speed * dt;
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += _speed * dt;
//
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotate(-_rotationSpeed * dt);
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rotate(_rotationSpeed * dt);
//
//     translate(movement.x, movement.y);
//
//     // Opcjonalnie: podążanie za myszką
//     if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//         sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//         _shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//     }
// }
