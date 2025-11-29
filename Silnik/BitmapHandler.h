#pragma once
#include <SFML/Graphics.hpp>
#include <string>

/// [lab5.1] Klasa do obsługi bitmap
class BitmapHandler {
public:
    ///Konstruktor
    ///Inicjalizuje obiekt BitmapHandler
    BitmapHandler();
    ///Destruktor
    ///Zwalnia zasoby zajmowane przez obiekt BitmapHandler
    ~BitmapHandler();

    /// Ładuje bitmapę z pliku
    bool loadFromFile(const std::string& filename);

    /// Zapisuje bitmapę do pliku
    bool saveToFile(const std::string& filename) const;

    /// kopiowanie całości
    void copyTo(BitmapHandler& other) const;

    /// kopiowanie fragmentu
    void copyRectTo(BitmapHandler& other, const sf::IntRect& rect, sf::Vector2i destPos);

    /// Zwraca referencję do wewnętrznego obiektu sf::Image
    const sf::Image& getImage() const { 
        return image; 
    }
    /// Zwraca referencję do wewnętrznego obiektu sf::Image (wersja niemodyfikowalna)
    sf::Image& getImage() { 
        return image; 
    }

private:
    /// Wewnętrzny obiekt sf::Image przechowujący bitmapę
    sf::Image image;
};