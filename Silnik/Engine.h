#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

/// Klasa silnika graficznego zarządzająca oknem i pętlą gry 
class Engine {
public:
    ///[lab1.2] Konstruktor silnika graficznego, tworzy okno SFML o podanych wymiarach i tytule 
    Engine(unsigned int width, unsigned int height, const string& title);
    ///  [lab1.4] Główna pętla gry 
    void run();
    /// [lab1.6] Ustawia kolor czyszczenia ekranu 
    void setClearColor(const sf::Color& color);

	// Usunięcie kopiowania i przypisania
private:
    sf::RenderWindow _window;
    sf::Clock _clock;
    float _deltaTime = 0.f;
    bool _isRunning = false;

    sf::Vector2i _mousePosition;
    sf::Color _clearColor = sf::Color::Black;

    
    
     ///  [lab1.3] Przetwarza zdarzenia wejściowe
     /*!
     *    -# zamkniecie okna przez uzytkownika
     *    -# zdarzenia myszki
     *         - wcisniecie przycisku myszy
     *         - zwolnienie przycisku myszy
     *         - ruch myszy
     *    -# zdarzenia klawiatury
     *         - wcisniecie klawisza
     *         - zwolnienie klawisza
     */
    void processEvents();
    ///  [lab1.5] Obsługa błędów z wejścia klawiatury
    void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);
    ///   [lab1.5] Obsługa błędów z wejścia myszy
    void handleMouseInput(sf::Mouse::Button button, bool isPressed);
    ///  Aktualizuje stan gry 
    void update(float dt);
    ///  [lab2.1] Renderuje scenę 
    void render();
    ///   [lab1.8] Zamyka silnik i zwalnia zasoby 
    void shutdown(); 
};
