#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics/Shape.hpp>

/// [lab4.1e] Klasa ShapeObject, która dziedziczy po klasach DrawableObject i TransformableObject
class ShapeObject : public DrawableObject, public TransformableObject {
protected:
    /// Figura
    sf::Shape* _shape = nullptr;

public:
    /// Destruktor 
    virtual ~ShapeObject();
    
    /// Metoda rysuj
    void draw(sf::RenderWindow& window) override;
    /// Metoda przesunięcia relatywnego
    void translate(float dx, float dy) override;
    /// Metoda rotacji
    void rotate(float angle) override;
    /// Metoda skalowania
    void scale(float factorX, float factorY) override;
    /// Metoda aktualizująca figure
    void update(float dt) override;
};

