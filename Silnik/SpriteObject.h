#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"

// [lab5.2 c] Klasa bazowa dla obiektów sprite'owych (animowanych z arkusza sprite'ów)
class SpriteObject : public BitmapObject, public AnimatedObject {
public:
    SpriteObject() = default;
    // Ustawia arkusz sprite'ów oraz parametry animacji
    void setSpriteSheet(const sf::Texture& tex, int frameW, int frameH, int framesPerAnim) {
        spriteSheet = &tex;
        frameWidth = frameW;
        frameHeight = frameH;
        frames = framesPerAnim;
        currentFrame = 0;

        sprite.setTexture(tex);
        sprite.setTextureRect({ 0, 0, frameW, frameH });
    }
    // Dziedziczone wirtualne metody
    virtual void draw(sf::RenderWindow&) = 0;
    virtual void translate(float, float) = 0;
    virtual void rotate(float) = 0;
    virtual void scale(float, float) = 0;
    // Implementacja metody animacji
    virtual void animate(float dt) override {
        time += dt;
        if (time >= frameTime) {
            time = 0;
            currentFrame = (currentFrame + 1) % frames;

            sprite.setTextureRect({
                currentFrame * frameWidth,
                currentDirection * frameHeight,
                frameWidth,
                frameHeight
                });
        }
    }

    void setDirection(int dir) { 
        currentDirection = dir; 
    }
    sf::Sprite& getSprite() { 
        return sprite; 
    }
    const sf::Sprite& getSprite() const { 
        return sprite; 
    }
    sf::Vector2f getPosition() const { 
        return getSprite().getPosition(); 
    }
protected:
    const sf::Texture* spriteSheet = nullptr;
    sf::Sprite sprite;

    int frameWidth = 0;
    int frameHeight = 0;
    int frames = 0;

    int currentFrame = 0;
    int currentDirection = 0; // 0=down,1=left,2=right,3=up

    float time = 0;
    float frameTime = 0.15f;
};