#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <filesystem>

Player::Player(float x, float y, float size)
    : _speed(200.f)
{
    // konfiguracja (dostosuj jeśli chcesz 60 FPS animacji)
    // Jeśli chcesz dokładnie 60 FPS dla zmiany klatek, ustaw animationFPS = 60.f;
    animationFPS = 10.f; // rekomendowane; zmień na 60.f jeśli tego chcesz

    // ustaw pojemność wektorów
    for (auto &v : textures) v.resize(framesPerDir);

    // nazwy plików — dostosuj do swoich nazw (użytkownik podał takie)
    // Sprawdź obie wersje dla player_right (z kropką i z podkreśleniem)
    struct NamePair { std::string name1, name2, name3; };
    std::array<NamePair,4> names = {
        NamePair{"player_down_1.png",  "player_down_2.png",  "player_down_3.png"},
        NamePair{"player_left_1.png",  "player_left_2.png",  "player_left_3.png"},
        NamePair{"player_right_1.png", "player_right_2.png", "player_right_3.png"}, // preferowana
        NamePair{"player_up_1.png",    "player_up_2.png", "player_up_3.png"}
    };

    // Jeśli masz inne nazwy: player_up_1.png player_up_2.png ...
    // Pętla ładuje pliki - akceptuje też wariant "player_right.2.png"
    for (int dir = 0; dir < 4; ++dir) {
        // pierwszy plik
        std::string p1 = "assets/" + names[dir].name1;
        if (!loadFrame(p1, static_cast<Direction>(dir), 0)) {
            // spróbuj zamiennika (np. jeśli user miał inny suffix)
            std::string alt1 = p1;
            std::replace(alt1.begin(), alt1.end(), '.', '_'); // np. player.right -> player_right (bez sensu ale bezpiecznie)
            loadFrame(alt1, static_cast<Direction>(dir), 0);
        }

        // drugi plik - tu obsługa literówki dla right: user miał "player_right.2.png"
        std::string p2 = "assets/" + names[dir].name2;
        if (!loadFrame(p2, static_cast<Direction>(dir), 1)) {
            // spróbuj alternatyw z kropką zamiast podkreślenia (obsługa literówki)
            std::string alt2 = p2;
            // example fix for the specific typo "player_right.2.png"
            size_t pos = alt2.find("right_2");
            if (pos == std::string::npos) {
                // try convert underscore to dot before the digit
                size_t underscore = alt2.find_last_of('_');
                if (underscore != std::string::npos) {
                    std::string tmp = alt2;
                    tmp[underscore] = '.'; // player_right.2.png
                    if (loadFrame(tmp, static_cast<Direction>(dir), 1)) continue;
                }
            } else {
                // already matched, nothing
            }
            // jeśli nadal nie wczytano, spróbuj zmiany kolejności (bezpiecznik)
            std::cout << "[Player] WARNING: couldn't load frame: " << p2 << "\n";
        }
    }

    // ustaw sprite pierwszą dostępną teksturą (bezpiecznie)
    applyCurrentFrame();

    getSprite().setPosition(x, y);
    getSprite().setScale(size / static_cast<float>(frameWidth), size / static_cast<float>(frameHeight));
}

bool Player::loadFrame(const std::string& path, Direction dir, int frameIndex) {
    namespace fs = std::filesystem;
    if (!fs::exists(path)) {
        // spróbuj jeszcze bez folderu assets (jeśli przetestujesz z innym wd)
        // wypisz dokładnie co nie istnieje
        std::cout << "[Player] file not found: " << path << "\n";
        return false;
    }

    auto tex = std::make_shared<sf::Texture>();
    if (!tex->loadFromFile(path)) {
        std::cout << "[Player] SFML failed to load: " << path << "\n";
        return false;
    }

    // upewnij się, że vektor ma miejsce
    if ((int)textures[dir].size() <= frameIndex) textures[dir].resize(frameIndex + 1);
    textures[dir][frameIndex] = tex;
    return true;
}

void Player::applyCurrentFrame() {
    // znajdź teksturę dla currentDirection/currentFrame (bezpiecznie, jeśli nie ma — nic nie rób)
    if (currentDirection < 0 || currentDirection >= 4) return;
    auto &vec = textures[static_cast<int>(currentDirection)];
    if (vec.empty() || currentFrame < 0 || currentFrame >= (int)vec.size() || !vec[currentFrame]) return;

    sprite.setTexture(*vec[currentFrame]);
    // ustaw origin i prostą skalę/pozycję jeśli trzeba
    sprite.setOrigin(frameWidth / 2.f, frameHeight / 2.f);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(getSprite());
}

void Player::translate(float dx, float dy) {
    getSprite().move(dx, dy);
}

void Player::rotate(float angle) {
    getSprite().rotate(angle);
}

void Player::scale(float sx, float sy) {
    getSprite().scale(sx, sy);
}

void Player::update(const sf::RenderWindow& window) {
    // dt: możesz podmienić na _deltaTime z Engine jeśli chcesz dokładny czas
    float dt = 1.f / 60.f;

    sf::Vector2f movement(0.f, 0.f);
    bool moved = false;
    Direction newDir = currentDirection;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= _speed * dt;
        newDir = Up;
        moved = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += _speed * dt;
        newDir = Down;
        moved = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= _speed * dt;
        newDir = Left;
        moved = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += _speed * dt;
        newDir = Right;
        moved = true;
    }

    translate(movement.x, movement.y);

    // animacja
    isMoving = moved;
    // jeśli zmiana kierunku -> resetuj licznik klatek
    if (newDir != currentDirection) {
        currentDirection = newDir;
        currentFrame = 0;
        timeAccumulator = 0.f;
        applyCurrentFrame();
    }

    if (isMoving) {
        timeAccumulator += dt;
        float frameTime = 1.0f / animationFPS; // sekundy na klatkę animacji
        if (timeAccumulator >= frameTime) {
            timeAccumulator -= frameTime;
            currentFrame = (currentFrame + 1) % framesPerDir;
            applyCurrentFrame();
        }
    } else {
        // spoczynek -> ustaw klatkę 0 (stopa "w neutralnej pozycji")
        if (currentFrame != 1) {
            currentFrame = 1;
            applyCurrentFrame();
        }
    }
}

/*
#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

Player::Player(float x, float y, float size, sf::Color color)
    : _speed(200.f), _rotationSpeed(120.f)
{
    _shape.setSize({ size, size });
    _shape.setOrigin(size / 2.f, size / 2.f);
    _shape.setFillColor(color);
    _shape.setPosition(x, y);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(_shape);
}

void Player::translate(float dx, float dy) {
    _shape.move(dx, dy);
}

void Player::rotate(float angle) {
    _shape.rotate(angle);
}

void Player::scale(float sx, float sy) {
    _shape.scale(sx, sy);
}

void Player::update(const sf::RenderWindow& window) {
    float dt = 1.f / 60.f; // możesz w przyszłości wprowadzić czasomierz z Engine
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= _speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += _speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= _speed * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += _speed * dt;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotate(-_rotationSpeed * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rotate(_rotationSpeed * dt);

    translate(movement.x, movement.y);

    // Opcjonalnie: podążanie za myszką
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        _shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}
*/