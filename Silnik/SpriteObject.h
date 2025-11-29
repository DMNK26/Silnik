#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"

/// [lab5.2 c] Klasa bazowa dla obiektów sprite'owych (animowanych z arkusza sprite'ów)
class SpriteObject : public BitmapObject, public AnimatedObject {
public:
    /// komentarz
    SpriteObject() = default;
    /// Ustawia arkusz sprite'ów oraz parametry animacji
    void setSpriteSheet(const sf::Texture& tex, int frameW, int frameH, int framesPerAnim) {
        spriteSheet = &tex;
        frameWidth = frameW;
        frameHeight = frameH;
        frames = framesPerAnim;
        currentFrame = 0;

        sprite.setTexture(tex);
        sprite.setTextureRect({ 0, 0, frameW, frameH });
    }
    /// komentarz
    virtual void draw(sf::RenderWindow&) = 0;
    /// komentarz
    virtual void translate(float, float) = 0;
    /// komentarz
    virtual void rotate(float) = 0;
    /// komentarz
    virtual void scale(float, float) = 0;
    /// Implementacja metody animacji
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
    /// komentarz
    void setDirection(int dir) { 
        currentDirection = dir; 
    }
    /// komentarz
    sf::Sprite& getSprite() { 
        return sprite; 
    }
    /// komentarz
    const sf::Sprite& getSprite() const { 
        return sprite; 
    }
    /// komentarz
    sf::Vector2f getPosition() const { 
        return getSprite().getPosition(); 
    }
protected:
    /// komentarz
    const sf::Texture* spriteSheet = nullptr;
    /// komentarz
    sf::Sprite sprite;
    /// komentarz
    int frameWidth = 0;
    /// komentarz
    int frameHeight = 0;
    /// komentarz
    int frames = 0;
    /// komentarz
    int currentFrame = 0;
    /// 0=down,1=left,2=right,3=up
    int currentDirection = 0; 
    /// komentarz
    float time = 0;
    /// komentarz
    float frameTime = 0.15f;
};