#pragma once
// [lab5.2 a] Klasa bazowa dla obiektów animowanych
class AnimatedObject {
public:
    virtual ~AnimatedObject() = default;
    virtual void animate(float dt) = 0;
};