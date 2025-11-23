#include "BitmapHandler.h"

// [lab5.1] Implementacja klasy BitmapHandler
BitmapHandler::BitmapHandler() {}
BitmapHandler::~BitmapHandler() {}

bool BitmapHandler::loadFromFile(const std::string& filename) {
    return image.loadFromFile(filename);
}

bool BitmapHandler::saveToFile(const std::string& filename) const {
    return image.saveToFile(filename);
}

void BitmapHandler::copyTo(BitmapHandler& other) const {
    other.image = this->image;
}

void BitmapHandler::copyRectTo(BitmapHandler& other, const sf::IntRect& rect, sf::Vector2i destPos) {
    other.image.copy(image, destPos.x, destPos.y, rect, true);
}