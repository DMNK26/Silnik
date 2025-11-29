//CAŁE DO ZAKOMENTOWANIA DLA RYSOWANIA KSZTAŁTÓW
#pragma once
#include "SpriteObject.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <memory>
#include <string>

// [Lab 5] Klasa reprezentująca gracza sterowanego przez użytkownika
class Player : public SpriteObject {
public:
    enum Direction { Down = 0, Left = 1, Right = 2, Up = 3 };

    Player(float x = 100.f, float y = 100.f, float size = 40.f);
    // dziedziczone wirtualne metody
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    void update(const sf::RenderWindow& window);

private:
    bool loadFrame(const std::string& path, Direction dir, int frameIndex);

    float _speed = 200.f;

    // 4 kierunki × 3 klatki
    std::array<std::vector<std::shared_ptr<sf::Texture>>, 4> textures;

    // animacja
    int framesPerDir = 3;
    Direction currentDirection = Down;
    int currentFrame = 1;
    float timeAccumulator = 0.f;
    float animationFPS = 10.f;

    bool isMoving = false;

    int frameWidth = 32;
    int frameHeight = 32;

    void applyCurrentFrame();
};



// CAŁE DO ODKOMENTOWANIA DO RYSOWANIA KSZTAŁTÓW
//
// #pragma once
// #include "ShapeObject.h"
// #include <SFML/Graphics.hpp>
//
// class Player : public ShapeObject {
// private:
//     sf::RectangleShape _shape;
//     float _speed;
//     float _rotationSpeed;
//
// public:
//     Player(float x = 100.f, float y = 100.f, float size = 40.f, sf::Color color = sf::Color::Blue);
//
//     // dziedziczone wirtualne metody
//     void draw(sf::RenderWindow& window) override;
//     void translate(float dx, float dy) override;
//     void rotate(float angle) override;
//     void scale(float sx, float sy) override;
//
//     // aktualizacja stanu gracza (wejście)
//     void update(const sf::RenderWindow& window);
//
//     // getter pozycji
//     sf::Vector2f getPosition() const { return _shape.getPosition(); }
// };
