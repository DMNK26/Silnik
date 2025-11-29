#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

//lab4.1e Obiekt linii łamanej dziedziczącej po ShapeObject
class PolylineObject : public ShapeObject {
public:
    PolylineObject(const std::vector<sf::Vector2f>& points, sf::Color color = sf::Color::White);

    PolylineObject(std::initializer_list<sf::Vector2f> points,
        sf::Color color = sf::Color::White)
        : PolylineObject(std::vector<sf::Vector2f>(points), color) {
    }

    virtual ~PolylineObject() = default;

    // Drawable
    void draw(sf::RenderWindow& window) override;

    // Transformable
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    // Updatable
    void update(float dt) override;

    // Additional utilities
    void setColor(sf::Color color);
    void addPoint(const sf::Vector2f& p);
    std::size_t getPointCount() const;

private:
    sf::VertexArray _vertices;
    std::vector<sf::Vector2f> _originalPoints;
    sf::Vector2f _origin;

    sf::Vector2f computeCentroid(const std::vector<sf::Vector2f>& pts) const;
    void rebuildVertexArray();
};
