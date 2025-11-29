#pragma once
/// [lab5.2 a] Klasa bazowa dla obiektów animowanych
class AnimatedObject {
public:
    /// Wirtualny destruktor. Zapewnia poprawne usuwanie obiektów pochodnych
    virtual ~AnimatedObject() = default;
    /// Metoda animująca obiekt
    /// \param dt Czas, jaki upłynął od ostatniej animacji
    virtual void animate(float dt) = 0;
};