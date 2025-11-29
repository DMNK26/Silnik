#include "BitmapHandler.h"

// [lab5.1] Implementacja klasy BitmapHandler
BitmapHandler::BitmapHandler() {}
BitmapHandler::~BitmapHandler() {}
// Ładuje bitmapę z pliku
bool BitmapHandler::loadFromFile(const std::string& filename) {
    return image.loadFromFile(filename);
}
// Zapisuje bitmapę do pliku
bool BitmapHandler::saveToFile(const std::string& filename) const {
    return image.saveToFile(filename);
}
// Zwraca referencję do wewnętrznego obiektu sf::Image
void BitmapHandler::copyTo(BitmapHandler& other) const {
    other.image = this->image;
}
// Kopiuje prostokątny obszar bitmapy do innej bitmapy
void BitmapHandler::copyRectTo(BitmapHandler& other, const sf::IntRect& rect, sf::Vector2i destPos) {
    other.image.copy(image, destPos.x, destPos.y, rect, true);
}