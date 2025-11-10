#include "Engine.h"
#include "Logger.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <iostream>
using namespace std;

/** [lab1.2] Konstruktor silnika graficznego, tworzy okno SFML o podanych wymiarach i tytule */
Engine::Engine(unsigned int width, unsigned int height, const string& title)
    : _window(sf::VideoMode(width, height), title)
{
    Logger::getInstance().log("Inicjalizacja silnika graficznego", Logger::Level::Info);
    _window.setFramerateLimit(60);
}

/**  [lab1.4] Główna pętla gry */
void Engine::run() {
    Logger::getInstance().log("Start glownej petli gry", Logger::Level::Info);
    _isRunning = true;

    while (_isRunning && _window.isOpen()) {
        _deltaTime = _clock.restart().asSeconds();
        processEvents();
        update(_deltaTime);
        render();
    }

    shutdown();
}


  /*!
   *  [lab1.3] Przetwarza zdarzenia wejściowe
   *    -# zamkniecie okna przez uzytkownika
   *    -# zdarzenia myszki
   *         - wcisniecie przycisku myszy
   *         - zwolnienie przycisku myszy
   *         - ruch myszy
   *    -# zdarzenia klawiatury
   *         - wcisniecie klawisza
   *         - zwolnienie klawisza
   */
void Engine::processEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            Logger::getInstance().log("Zamkniecie okna przez uzytkownika", Logger::Level::Info);
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

/**  [lab1.5] Obsługa błędów z wejścia klawiatury*/
void Engine::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
    if (isPressed)
        Logger::getInstance().log("Wcisniety klawisz: " + to_string(key), Logger::Level::Debug);
    else
        Logger::getInstance().log("Zwolniony klawisz: " + to_string(key), Logger::Level::Debug);

    if (key == sf::Keyboard::Escape && isPressed)
        _isRunning = false; // zakończ grę
}

/**   [lab1.5] Obsługa błędów z wejścia myszy*/
void Engine::handleMouseInput(sf::Mouse::Button button, bool isPressed) {
    if (isPressed)
        Logger::getInstance().log("Wcisniety przycisk myszy: " + to_string(button), Logger::Level::Debug);
    else
        Logger::getInstance().log("Zwolniony przycisk myszy:" + to_string(button), Logger::Level::Debug);
}

/** [lab1.6] Ustawia kolor czyszczenia ekranu */
void Engine::setClearColor(const sf::Color& color) {
    _clearColor = color;
}

/**  Aktualizuje stan gry */
void Engine::update(float dt) {
    // logika gry, aktualizacja obiektów
}

/**  [lab2.1] Renderuje scenę */
void Engine::render() {
    _window.clear(_clearColor);

	 // [lab2 / lab3] TEST DO RYSOWANIA PRYMITYWÓW 

    PrimitiveRenderer renderer(_window);

    /** [lab2] Rysowanie punktu */ 
    Point2D p1(100, 100);
    p1.draw(renderer, sf::Color::Yellow);

    /** [lab2] Rysowanie kilku punktów*/
    for (int i = 0; i < 10; ++i) {
        Point2D p(50 + i * 10, 200);
        p.draw(renderer, sf::Color::Green);
    }

    /** [lab2] Rysowanie odcinka domyślnie (SFML)*/
    LineSegment lineA({ 100, 300 }, { 300, 350 });
    lineA.draw(renderer, false, sf::Color::Cyan);

    /** [lab2]Rysowanie odcinka algorytmem przyrostowym*/
    LineSegment lineB({ 100, 400 }, { 300, 500 });
    lineB.draw(renderer, true, sf::Color::Red);

    /** [lab2] Rysowanie linii łamanej (otwartej) */
    std::vector<Point2D> poly = { {400,100}, {450,150}, {500,100}, {550,150} };
    renderer.drawPolyline(poly, sf::Color::Magenta, false);
    

    /**  [lab 3.1] Rysowanie okregu 8 - krotną symetrią */
	renderer.drawCircleSymmetry({ 800, 100 }, 50, sf::Color::White);

	/**  [lab 3.2] Rysowanie elipsy 8-krotną symetrią */
	renderer.drawEllipseSymmetry({ 800, 225 }, 50, 30, sf::Color::White);

    /**  [lab 3.3] Wiekokąty*/
    std::vector<sf::Vector2f> figure1 = { {850, 300}, {900, 375},{850, 450},  {750, 450}, {700, 375}, {750, 300} };
    renderer.drawPolygon(figure1, sf::Color::White);
 
    std::vector<sf::Vector2f> figure2 = { {650, 500}, { 750,500 }, { 750,600}, {650, 600} };
    renderer.drawPolygon(figure2, sf::Color::White);
    
    /**  [lab 3.4] Wypełniony wielokat i koło*/
    std::vector<sf::Vector2f> figure3 = { {800, 500}, { 900,500 }, { 900,600}, {800, 600} };
	renderer.drawFilledPolygon(figure3, sf::Color::White);

	renderer.drawFilledCircle({ 1000, 550 }, 50, sf::Color::White);

    /**  [lab3.5] Wypełnianie obszarów floodfill*/
    std::vector<sf::Vector2f> figure4 = { {650, 650}, { 750,650 }, { 750,750}, {650, 750} };
    renderer.drawPolygon(figure4, sf::Color::White);
    //Point2D point4(700, 700);
    //point4.draw(renderer, sf::Color::Red);

    renderer.floodfill({ 700, 700 }, sf::Color(255, 200, 230));

	/** [lab3.5] Wypełnianie obszarów borderfill*/
    std::vector<sf::Vector2f> figure5 = { {800, 650}, { 900,650 }, { 900,750}, {800, 750} };
    renderer.drawPolygon(figure5, sf::Color::White);
    Point2D point5(850, 700);
    point5.draw(renderer, sf::Color::Red);

    renderer.borderfill({ 850.f, 700.f }, sf::Color(200, 240, 255), sf::Color::White);
    
    _window.display();
}

/**   [lab1.8] Zamyka silnik i zwalnia zasoby */
void Engine::shutdown() {
    Logger::getInstance().log("Rozpoczynanie procesu zamykania silnika", Logger::Level::Info);

    // Tutaj w przyszłości:
    // - zwolnimy zasoby (tekstury, dźwięki, shadery itp.)
    // - zatrzymamy podsystemy (audio, sieć, fizyka)

    if (_window.isOpen()) {
        _window.close();
        Logger::getInstance().log("Okno SFML zostalo zamkniete", Logger::Level::Info);
    }

    Logger::getInstance().log("Silnik zamkniety pomyslnie ", Logger::Level::Info);
}
