#pragma once
#include <SFML/Graphics.hpp>

/** [lab4.1] podpunkt a */
class GameObject {
public:
    virtual ~GameObject() = default;

    // Inicjalizacja zasobów, jeśli potrzebne
    virtual void init() {}

    // Czysto wirtualne metody, które mogą być wspólne dla wszystkich obiektów
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};
