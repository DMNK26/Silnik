#include "Engine.h"
#include "Logger.h"
#include <iostream>
using namespace std;

Engine::Engine(unsigned int width, unsigned int height, const string& title)
    : _window(sf::VideoMode(width, height), title)
{
    Logger::getInstance().log("Inicjalizacja silnika graficznego...", Logger::Level::Info);
    _window.setFramerateLimit(60);
}

void Engine::run() {
    Logger::getInstance().log("Start głównej pętli gry", Logger::Level::Info);
    _isRunning = true;

    while (_isRunning && _window.isOpen()) {
        _deltaTime = _clock.restart().asSeconds();
        processEvents();
        update(_deltaTime);
        render();
    }

    shutdown();
}

void Engine::setClearColor(const sf::Color& color) {
    _clearColor = color;
}

void Engine::processEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            Logger::getInstance().log("Zamknięcie okna przez użytkownika", Logger::Level::Info);
            _isRunning = false;
            break;

        case sf::Event::KeyPressed:
            handleKeyboardInput(event.key.code, true);
            break;

        case sf::Event::KeyReleased:
            handleKeyboardInput(event.key.code, false);
            break;

        case sf::Event::MouseButtonPressed:
            handleMouseInput(event.mouseButton.button, true);
            break;

        case sf::Event::MouseButtonReleased:
            handleMouseInput(event.mouseButton.button, false);
            break;

        case sf::Event::MouseMoved:
            _mousePosition = sf::Mouse::getPosition(_window);
            break;

        default:
            break;
        }
    }
}

void Engine::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
    if (isPressed)
        Logger::getInstance().log("Key pressed: " + to_string(key), Logger::Level::Debug);
    else
        Logger::getInstance().log("Key released: " + to_string(key), Logger::Level::Debug);

    if (key == sf::Keyboard::Escape && isPressed)
        _isRunning = false; // zakończ grę
}

void Engine::handleMouseInput(sf::Mouse::Button button, bool isPressed) {
    if (isPressed)
        Logger::getInstance().log("Mouse pressed: " + to_string(button), Logger::Level::Debug);
    else
        Logger::getInstance().log("Mouse released: " + to_string(button), Logger::Level::Debug);
}

void Engine::update(float dt) {
    // logika gry, aktualizacja obiektów
}

void Engine::render() {
    _window.clear(_clearColor);
    // tu rysujemy obiekty
    _window.display();
}

void Engine::shutdown() {
    Logger::getInstance().log("Rozpoczynanie procesu zamykania silnika...", Logger::Level::Info);

    // 🧹 Tutaj w przyszłości:
    // - zwolnimy zasoby (tekstury, dźwięki, shadery itp.)
    // - zatrzymamy podsystemy (audio, sieć, fizyka)

    if (_window.isOpen()) {
        _window.close();
        Logger::getInstance().log("Okno SFML zostało zamknięte", Logger::Level::Info);
    }

    Logger::getInstance().log("Silnik zamknięty pomyślnie ✅", Logger::Level::Info);
}
