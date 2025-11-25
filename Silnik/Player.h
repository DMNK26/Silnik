#pragma once
#include "SpriteObject.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <memory>
#include <string>

class Player : public SpriteObject {
public:
    enum Direction { Down = 0, Left = 1, Right = 2, Up = 3 };

    Player(float x = 200.f, float y = 200.f, float size = 50.f);

    // nadpisania z SpriteObject
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    void update(const sf::RenderWindow& window);

private:
    // ładowanie plików
    bool loadFrame(const std::string& path, Direction dir, int frameIndex);

    float _speed = 200.f;

    // tekstury: directions x frames_per_direction
    std::array<std::vector<std::shared_ptr<sf::Texture>>, 4> textures;

    // animacja
    int framesPerDir = 3; // masz 3 pliki na kierunek
    Direction currentDirection = Down;
    int currentFrame = 0;
    float timeAccumulator = 0.f;
    float animationFPS = 10.f; // domyślnie 10 FPS -> ~0.1s per frame
    bool isMoving = false;

    // rozmiar klatki (u Ciebie 32x32)
    int frameWidth = 32;
    int frameHeight = 32;

    // pomoc: ustawia sprite z tekstury ramki
    void applyCurrentFrame();
};




/*
#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>

class Player : public ShapeObject {
private:
    sf::RectangleShape _shape;
    float _speed;
    float _rotationSpeed;

public:
    Player(float x = 100.f, float y = 100.f, float size = 40.f, sf::Color color = sf::Color::Blue);

    // dziedziczone wirtualne metody
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    // aktualizacja stanu gracza (wejście)
    void update(const sf::RenderWindow& window);

    // getter pozycji
    sf::Vector2f getPosition() const { return _shape.getPosition(); }
};
*/