#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics/Shape.hpp>

/// [lab4.1e]
class ShapeObject : public DrawableObject, public TransformableObject {
protected
    /// komentarz
    sf::Shape* _shape = nullptr;

public:
    /// komentarz
    virtual ~ShapeObject();
    
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    /// komentarz
    void rotate(float angle) override;
    /// komentarz
    void scale(float factorX, float factorY) override;
    void update(float dt) override;
};

