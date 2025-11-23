#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// [lab5.1] Klasa do obsługi bitmap
class BitmapHandler {
public:
    BitmapHandler();
    ~BitmapHandler();

    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    // kopiowanie całości
    void copyTo(BitmapHandler& other) const;

    // kopiowanie fragmentu
    void copyRectTo(BitmapHandler& other, const sf::IntRect& rect, sf::Vector2i destPos);

    const sf::Image& getImage() const { 
        return image; 
    }
    sf::Image& getImage() { 
        return image; 
    }

private:
    sf::Image image;
};