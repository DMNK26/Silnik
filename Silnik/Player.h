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
    /// Kierunki ruchu
    enum Direction { Down = 0, Left = 1, Right = 2, Up = 3 };
    /// Konstruktor gracza z początkową pozycją i rozmiarem
    Player(float x = 100.f, float y = 100.f, float size = 40.f);
    /// Metoda rysująca gracza na oknie
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesuwająca gracza o (dx, dy)
    void translate(float dx, float dy) override;
    /// Metoda obracająca gracza o kąt angle
    void rotate(float angle) override;
    /// Metoda skalująca gracza o (sx, sy)
    void scale(float sx, float sy) override;

    /// Metoda aktualizująca stan gracza na podstawie wejścia użytkownika
    void update(const sf::RenderWindow& window);

private:
    /// Ładuje pojedynczą klatkę animacji z pliku
    bool loadFrame(const std::string& path, Direction dir, int frameIndex);

    /// Prędkość ruchu gracza
    float _speed = 200.f;

    /// 4 kierunki × 3 klatki
    std::array<std::vector<std::shared_ptr<sf::Texture>>, 4> textures;

    /// Liczba klatek na kierunek
    int framesPerDir = 3;
    /// Aktualny kierunek
    Direction currentDirection = Down;
    /// Aktualna klatka
    int currentFrame = 1;
    /// Akumulator czasu do animacji
    float timeAccumulator = 0.f;
    /// Liczba klatek na sekundę animacji
    float animationFPS = 10.f;
    /// Czy gracz się porusza
    bool isMoving = false;
    /// Szerokość pojedynczej klatki
    int frameWidth = 32;
    /// Wysokość pojedynczej klatki
    int frameHeight = 32;

    /// Zastosowuje aktualną klatkę animacji do sprite'a
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
