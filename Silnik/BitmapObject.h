#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

// [lab5.2 b] Klasa bazowa dla obiektów bitmapowych
class BitmapObject : public sf::Drawable, public sf::Transformable {
public:
    BitmapObject() = default;

    void addTexture(const sf::Texture& tex) {
        sprites.emplace_back(tex);
    }

protected:
    std::vector<sf::Sprite> sprites;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        if (sprites.empty())
            return;

        states.transform *= getTransform();
        for (const auto& s : sprites)
            target.draw(s, states);
    }
};