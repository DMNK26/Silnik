#pragma once
/// [lab5.2 a] Klasa bazowa dla obiektów animowanych
class AnimatedObject {
public:
    /// komentarz
    virtual ~AnimatedObject() = default;
    /// komentarz
    virtual void animate(float dt) = 0;
};