#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"

/// [lab5.2 c] Klasa bazowa dla obiektów sprite'owych (animowanych z arkusza sprite'ów)
class SpriteObject : public BitmapObject, public AnimatedObject {
public:
    /// Wirtualny destruktor. Zapewnia poprawne usuwanie obiektów pochodnych
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
    /// Metoda rysująca obiekt na oknie
    virtual void draw(sf::RenderWindow&) = 0;
    /// Metoda przesuwająca obiekt o (dx, dy)
    virtual void translate(float, float) = 0;
    /// Metoda obracająca obiekt o kąt angle
    virtual void rotate(float) = 0;
    /// Metoda skalująca obiekt o (sx, sy)
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
    /// Ustawia kierunek animacji
    void setDirection(int dir) { 
        currentDirection = dir; 
    }
    /// Zwraca referencję do sprite'a
    sf::Sprite& getSprite() { 
        return sprite; 
    }
    /// Zwraca referencję do sprite'a (wersja niemodyfikowalna)
    const sf::Sprite& getSprite() const { 
        return sprite; 
    }
    /// Zwraca pozycję obiektu
    sf::Vector2f getPosition() const { 
        return getSprite().getPosition(); 
    }
protected:
    /// Wskaźnik na arkusz sprite'ów
    const sf::Texture* spriteSheet = nullptr;
    /// Sprite reprezentujący obiekt
    sf::Sprite sprite;
    /// Szerokość pojedynczej klatki
    int frameWidth = 0;
    /// Wysokość pojedynczej klatki
    int frameHeight = 0;
    /// Liczba klatek w animacji
    int frames = 0;
    /// Aktualna klatka animacji
    int currentFrame = 0;
    /// 0=down,1=left,2=right,3=up
    int currentDirection = 0; 
    /// Akumulator czasu do animacji
    float time = 0;
    /// Czas trwania pojedynczej klatki animacji
    float frameTime = 0.15f;
};