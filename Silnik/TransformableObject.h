#pragma once
#include "GameObject.h"

/// [lab4.1d] Klasa TransformableObject, która dziedziczy po klasie GameObject, dodaje metody manipulacji obiektem
class TransformableObject : virtual public GameObject {
public:
    /// Wirtualna metoda przesunięcia relatywnego
    virtual void translate(float dx, float dy) = 0;
    /// Wirtualna metoda rotacji
    virtual void rotate(float angle) = 0;
    /// Wirtualna metoda skalowania
    virtual void scale(float factorX, float factorY) = 0;
};
