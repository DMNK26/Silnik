#include "PrimitiveRenderer.h"
#include <cmath>
#include <stack>


// lab2.2 Implementacja klasy PrimitiveRenderer

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

// lab2.3 Rysowanie linii między dwoma punktami metodą przyrostową (Bresenhama)
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

// lab2.6 Rysowanie polilinii z podanej listy punktów, opcjonalnie zamkniętej
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

//lab 3.1 Rysowanie okregu 8-krotną symetrią
void PrimitiveRenderer::drawCircleSymmetry(sf::Vector2f center, float radius, sf::Color color) {
    float x = 0;
    float y = radius;
    float d = 1 - radius;
    while (x <= y) {
        drawPoint(center.x + x, center.y + y, color);
        drawPoint(center.x - x, center.y + y, color);
        drawPoint(center.x + x, center.y - y, color);
        drawPoint(center.x - x, center.y - y, color);
        drawPoint(center.x + y, center.y + x, color);
        drawPoint(center.x - y, center.y + x, color);
        drawPoint(center.x + y, center.y - x, color);
        drawPoint(center.x - y, center.y - x, color);
        if (d < 0) {
            d += 2 * x + 3; 
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

// lab3.2 Rysowanie elipsy z wykorzystaniem symetrii
void PrimitiveRenderer::drawEllipseSymmetry(sf::Vector2f center, float a, float b, sf::Color color) {
    float x = 0;
    float y = b;
    float a2 = a * a;
    float b2 = b * b;
    float d1 = b2 - a2 * b + 0.25f * a2;
    while (b2 * x < a2 * y) {
        drawPoint(center.x + x, center.y + y, color);
        drawPoint(center.x - x, center.y + y, color);
        drawPoint(center.x + x, center.y - y, color);
        drawPoint(center.x - x, center.y - y, color);
        if (d1 < 0) {
            d1 += b2 * (2 * x + 3);
        } else {
            d1 += b2 * (2 * x + 3) + a2 * (-2 * y + 2);
            y--;
        }
        x++;
    }
    float d2 = b2 * (x + 0.5f) * (x + 0.5f) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        drawPoint(center.x + x, center.y + y, color);
        drawPoint(center.x - x, center.y + y, color);
        drawPoint(center.x + x, center.y - y, color);
        drawPoint(center.x - x, center.y - y, color);
        if (d2 > 0) {
            d2 += a2 * (-2 * y + 3);
        } else {
            d2 += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
            x++;
        }
        y--;
    }
}

// lab3.3 Rysowanie wielokąta z kontrolą przecinania się odcinków
void PrimitiveRenderer::drawPolygon(const std::vector<sf::Vector2f>& vertices, sf::Color color) {
    if (vertices.size() < 3) return;

    // przygotowanie listy krawędzi 
    struct Segment {
        sf::Vector2f p1;
        sf::Vector2f p2;
    };
    std::vector<Segment> segments;
    for (size_t i = 0; i < vertices.size(); ++i) {
        segments.push_back({ vertices[i], vertices[(i + 1) % vertices.size()] });
    }

    // funkcja pomocnicza sprawdzająca przecięcie 
    auto orientation = [](const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c) {
        float val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
        if (std::abs(val) < 1e-6) return 0;  // kolinearne
        return (val > 0) ? 1 : 2;            // zgodne lub przeciwne z ruchem wskazówek zegara
        };

    auto onSegment = [](const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c) {
        return (std::min(a.x, c.x) <= b.x && b.x <= std::max(a.x, c.x) &&
            std::min(a.y, c.y) <= b.y && b.y <= std::max(a.y, c.y));
        };

    auto segmentsIntersect = [&](const Segment& s1, const Segment& s2) {
        const sf::Vector2f& p1 = s1.p1;
        const sf::Vector2f& q1 = s1.p2;
        const sf::Vector2f& p2 = s2.p1;
        const sf::Vector2f& q2 = s2.p2;

        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        // Przypadek ogólny
        if (o1 != o2 && o3 != o4) return true;

        // Przypadki szczególne (kolinearne)
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;

        return false;
        };

    // sprawdzenie przecinania się krawędzi
    for (size_t i = 0; i < segments.size(); ++i) {
        for (size_t j = i + 1; j < segments.size(); ++j) {
            // Pomijamy krawędzie sąsiednie (dzielą wspólny wierzchołek)
            if (j == i || j == (i + 1) % segments.size() || i == (j + 1) % segments.size())
                continue;

            if (segmentsIntersect(segments[i], segments[j])) {
                // Znaleziono przecięcie -> łamana wiązana
                std::cout << "Przecięcie odcinków - rysowanie przerwane." << std::endl;
                return;
            }
        }
    }

    // rysowanie, jeśli nie ma przecięć
    for (const auto& seg : segments) {
        drawLine(seg.p1, seg.p2, color);
    }
}

// lab3.4 Rysowanie wypełnionego wielokąta
void PrimitiveRenderer:: drawFilledPolygon 
(const std::vector<sf::Vector2f>& vertices, sf::Color color) {
    if (vertices.size() < 3) return;
    sf::ConvexShape polygon;
    polygon.setPointCount(vertices.size());
    for (size_t i = 0; i < vertices.size(); ++i) {
        polygon.setPoint(i, vertices[i]);
    }
    polygon.setFillColor(color);
    _window.draw(polygon);
}  
// lab3.4 Rysowanie wypełnionego koła
void PrimitiveRenderer:: drawFilledCircle(sf::Vector2f center, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(color);
    _window.draw(circle);
}

// lab3.5 Wypełnianie obszaru metodą border fill
void PrimitiveRenderer:: borderfill (sf::Vector2f seedPoint, sf::Color fillColor, sf::Color boundaryColor) {
    sf::Texture texture;
    texture.create(_window.getSize().x, _window.getSize().y);
    texture.update(_window);
    sf::Image image = texture.copyToImage();

    sf::Color currentColor = image.getPixel(static_cast<unsigned int>(seedPoint.x), static_cast<unsigned int>(seedPoint.y));
    if (currentColor == boundaryColor || currentColor == fillColor) {
        return; // Punkt startowy jest na granicy lub już wypełniony
    }
    std::stack<sf::Vector2f> pixelStack;
    pixelStack.push(seedPoint);
    while (!pixelStack.empty()) {
        sf::Vector2f p = pixelStack.top();
        pixelStack.pop();
        unsigned int x = static_cast<unsigned int>(p.x);
        unsigned int y = static_cast<unsigned int>(p.y);
        if (x >= image.getSize().x || y >= image.getSize().y) continue;
        currentColor = image.getPixel(x, y);
        if (currentColor != boundaryColor && currentColor != fillColor) {
            image.setPixel(x, y, fillColor);
            pixelStack.push(sf::Vector2f(static_cast<float>(x + 1), static_cast<float>(y)));
            pixelStack.push(sf::Vector2f(static_cast<float>(x - 1), static_cast<float>(y)));
            pixelStack.push(sf::Vector2f(static_cast<float>(x), static_cast<float>(y + 1)));
            pixelStack.push(sf::Vector2f(static_cast<float>(x), static_cast<float>(y - 1)));

        }
    }

    sf::Sprite sprite(texture);
    _window.draw(sprite);
}

// lab3.5 Wypełnianie obszaru metodą flood fill
void PrimitiveRenderer:: floodfill(sf::Vector2f seedPoint, sf::Color fillColor) {
    sf::Texture texture;
    texture.create(_window.getSize().x, _window.getSize().y);
    texture.update(_window);
    sf::Image image = texture.copyToImage();

    sf::Color targetColor = image.getPixel(static_cast<unsigned int>(seedPoint.x), static_cast<unsigned int>(seedPoint.y));
    if (targetColor == fillColor) {
        return; // Punkt startowy jest już wypełniony
    }
    std::stack<sf::Vector2f> pixelStack;
    pixelStack.push(seedPoint);
    while (!pixelStack.empty()) {
        sf::Vector2f p = pixelStack.top();
        pixelStack.pop();
        unsigned int x = static_cast<unsigned int>(p.x);
        unsigned int y = static_cast<unsigned int>(p.y);
        if (x >= image.getSize().x || y >= image.getSize().y) continue;
        sf::Color currentColor = image.getPixel(x, y);
        if (currentColor == targetColor) {
            image.setPixel(x, y, fillColor);
            pixelStack.push(sf::Vector2f(static_cast<float>(x + 1), static_cast<float>(y)));
            pixelStack.push(sf::Vector2f(static_cast<float>(x - 1), static_cast<float>(y)));
            pixelStack.push(sf::Vector2f(static_cast<float>(x), static_cast<float>(y + 1)));
            pixelStack.push(sf::Vector2f(static_cast<float>(x), static_cast<float>(y - 1)));

        }
    }

    sf::Sprite sprite(texture);
    _window.draw(sprite);
}
