#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics/Shape.hpp>

//Lab4.1e
class ShapeObject : public DrawableObject, public TransformableObject {
protected:
    sf::Shape* _shape = nullptr;

public:
    virtual ~ShapeObject();
    
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factorX, float factorY) override;
    void update(float dt) override;
};

