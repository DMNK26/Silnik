#include "PrimitiveRenderer.h"
#include <cmath>

//Przechowywanie referencji do okna, na którym będą rysowane prymitywy
PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window)
    : _window(window) {
}

// Rysowanie pojedynczego punktu o danych współrzędnych i kolorze
void PrimitiveRenderer::drawPoint(float x, float y, sf::Color color) {
    sf::Vertex point(sf::Vector2f(x, y), color);
    _window.draw(&point, 1, sf::Points);
}

// Rysowanie linii między dwoma punktami o danym kolorze
void PrimitiveRenderer::drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color) {
    sf::Vertex line[] = { sf::Vertex(p1, color), sf::Vertex(p2, color) };
    _window.draw(line, 2, sf::Lines);
}


// Rysowanie prostokąta o podanym prostokątnym obszarze i kolorze
void PrimitiveRenderer::drawRectangle(sf::FloatRect rect, sf::Color color) {
    sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(rect.left, rect.top);
    shape.setFillColor(color);
    _window.draw(shape);
}

// Rysowanie koła o podanym środku, promieniu i kolorze
void PrimitiveRenderer::drawCircle(sf::Vector2f center, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(color);
    _window.draw(circle);
}


// Rysowanie linii między dwoma punktami metodą przyrostową (Bresenhama)
void PrimitiveRenderer::drawLineIncremental(sf::Vector2f p1, sf::Vector2f p2, sf::Color color) {
    float x0 = p1.x;
    float y0 = p1.y;
    float x1 = p2.x;
    float y1 = p2.y;

    float dx = x1 - x0;
    float dy = y1 - y0;

    // jeśli nachylenie mniejsze niż 1
    if (std::abs(dy) <= std::abs(dx)) {
        if (x0 > x1) std::swap(x0, x1), std::swap(y0, y1);
        float m = dy / dx;
        float y = y0;
        for (float x = x0; x <= x1; x++) {
            drawPoint(x, std::round(y), color);
            y += m;
        }
    }
    // dla nachylenia |m| > 1
    else {
        if (y0 > y1) std::swap(x0, x1), std::swap(y0, y1);
        float m = dx / dy;
        float x = x0;
        for (float y = y0; y <= y1; y++) {
            drawPoint(std::round(x), y, color);
            x += m;
        }
    }
}

// Rysowanie polilinii z podanej listy punktów, opcjonalnie zamkniętej
void PrimitiveRenderer::drawPolyline(const std::vector<Point2D>& points, sf::Color color, bool closed) {
    if (points.size() < 2) return;

    for (size_t i = 0; i < points.size() - 1; ++i) {
        drawLine(
            { points[i].getX(), points[i].getY() },
            { points[i + 1].getX(), points[i + 1].getY() },
            color
        );
    }

    if (closed) {
        drawLine(
            { points.back().getX(), points.back().getY() },
            { points.front().getX(), points.front().getY() },
            color
        );
    }
}