#pragma once
#include <SFML/Graphics.hpp>
#include <string>

/// [lab5.1] Klasa do obsługi bitmap
class BitmapHandler {
public:
    /// komentarz
    BitmapHandler();
    /// komentarz
    ~BitmapHandler();

    /// komentarz
    bool loadFromFile(const std::string& filename);

    /// komentarz
    bool saveToFile(const std::string& filename) const;

    /// kopiowanie całości
    void copyTo(BitmapHandler& other) const;

    /// kopiowanie fragmentu
    void copyRectTo(BitmapHandler& other, const sf::IntRect& rect, sf::Vector2i destPos);

    /// komentarz
    const sf::Image& getImage() const { 
        return image; 
    }
    /// komentarz
    sf::Image& getImage() { 
        return image; 
    }

private:
    /// komentarz
    sf::Image image;
};