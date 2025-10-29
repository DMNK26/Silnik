#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

/**  Klasa silnika graficznego zarządzająca oknem i pętlą gry */
class Engine {
public:
    Engine(unsigned int width, unsigned int height, const string& title);
    void run();
    void setClearColor(const sf::Color& color);

	// Usunięcie kopiowania i przypisania
private:
    sf::RenderWindow _window;
    sf::Clock _clock;
    float _deltaTime = 0.f;
    bool _isRunning = false;

    sf::Vector2i _mousePosition;
    sf::Color _clearColor = sf::Color::Black;

    

    void processEvents();
    void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);
    void handleMouseInput(sf::Mouse::Button button, bool isPressed);
    void update(float dt);
    void render();
    void shutdown(); 
};
