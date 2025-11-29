//CAŁE DO ZAKOMENTOWANIA DLA RYSOWANIA KSZTAŁTÓW
#pragma once
#include "SpriteObject.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <memory>
#include <string>

///[lab 5] Klasa reprezentująca gracza sterowanego przez użytkownika
class Player : public SpriteObject {
public:
    /// komentarz
    enum Direction { Down = 0, Left = 1, Right = 2, Up = 3 };
    /// komentarz
    Player(float x = 100.f, float y = 100.f, float size = 40.f);
    /// komentarz
    void draw(sf::RenderWindow& window) override;
    /// komentarz
    void translate(float dx, float dy) override;
    /// komentarz
    void rotate(float angle) override;
    /// komentarz
    void scale(float sx, float sy) override;

    /// komentarz
    void update(const sf::RenderWindow& window);

private:
    /// komentarz
    bool loadFrame(const std::string& path, Direction dir, int frameIndex);

    /// komentarz
    float _speed = 200.f;

    /// 4 kierunki × 3 klatki
    std::array<std::vector<std::shared_ptr<sf::Texture>>, 4> textures;

    /// animacja
    int framesPerDir = 3;
    /// komentarz
    Direction currentDirection = Down;
    /// komentarz
    int currentFrame = 1;
    /// komentarz
    float timeAccumulator = 0.f;
    /// komentarz
    float animationFPS = 10.f;
    /// komentarz
    bool isMoving = false;
    /// komentarz
    int frameWidth = 32;
    /// komentarz
    int frameHeight = 32;

    /// komentarz
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
