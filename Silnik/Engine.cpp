#include "Engine.h"
#include "Logger.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <iostream>
using namespace std;

// Konstruktor silnika graficznego, tworzy okno SFML o podanych wymiarach i tytule
Engine::Engine(unsigned int width, unsigned int height, const string& title)
    : _window(sf::VideoMode(width, height), title)
{
    Logger::getInstance().log("Inicjalizacja silnika graficznego...", Logger::Level::Info);
    _window.setFramerateLimit(60);
}

// Główna pętla gry
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

// Ustawia kolor czyszczenia ekranu
void Engine::setClearColor(const sf::Color& color) {
    _clearColor = color;
}

// Przetwarza zdarzenia wejściowe
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

// Obsługuje wejście z klawiatury
void Engine::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
    if (isPressed)
        Logger::getInstance().log("Key pressed: " + to_string(key), Logger::Level::Debug);
    else
        Logger::getInstance().log("Key released: " + to_string(key), Logger::Level::Debug);

    if (key == sf::Keyboard::Escape && isPressed)
        _isRunning = false; // zakończ grę
}

// Obsługuje wejście z myszy
void Engine::handleMouseInput(sf::Mouse::Button button, bool isPressed) {
    if (isPressed)
        Logger::getInstance().log("Mouse pressed: " + to_string(button), Logger::Level::Debug);
    else
        Logger::getInstance().log("Mouse released: " + to_string(button), Logger::Level::Debug);
}

// Aktualizuje stan gry
void Engine::update(float dt) {
    // logika gry, aktualizacja obiektów
}

// Renderuje scenę
void Engine::render() {
    _window.clear(_clearColor);
    // tu rysujemy obiekty


	/* TEST DO RYSOWANIA PRYMITYWÓW

    PrimitiveRenderer renderer(_window);

    // 🔹 Rysowanie punktu
    Point2D p1(100, 100);
    p1.draw(renderer, sf::Color::Yellow);

    // 🔹 Rysowanie kilku punktów
    for (int i = 0; i < 10; ++i) {
        Point2D p(50 + i * 10, 200);
        p.draw(renderer, sf::Color::Green);
    }

    // 🔹 Rysowanie odcinka domyślnie (SFML)
    LineSegment lineA({ 100, 300 }, { 300, 350 });
    lineA.draw(renderer, false, sf::Color::Cyan);

    // 🔹 Rysowanie odcinka algorytmem przyrostowym
    LineSegment lineB({ 100, 400 }, { 300, 500 });
    lineB.draw(renderer, true, sf::Color::Red);

    // 🔹 Rysowanie linii łamanej (otwartej)
    std::vector<Point2D> poly = { {400,100}, {450,150}, {500,100}, {550,150} };
    renderer.drawPolyline(poly, sf::Color::Magenta, false);
    */

    _window.display();
}

// Zamyka silnik i zwalnia zasoby
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
