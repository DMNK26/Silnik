#pragma once
#include "ShapeObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

///[lab4.1e] Obiekt linii łamanej dziedziczącej po ShapeObject
class PolylineObject : public ShapeObject {
public:
    /// komentarz
    PolylineObject(const std::vector<sf::Vector2f>& points, sf::Color color = sf::Color::White);

    /// komentarz
    PolylineObject(std::initializer_list<sf::Vector2f> points,
        sf::Color color = sf::Color::White)
        : PolylineObject(std::vector<sf::Vector2f>(points), color) {
    }
    /// komentarz
    virtual ~PolylineObject() = default;

    /// Drawable
    void draw(sf::RenderWindow& window) override;

    /// Transformable
    void translate(float dx, float dy) override;

    /// komentarz
    void rotate(float angle) override;

    /// komentarz
    void scale(float sx, float sy) override;

    /// Updatable
    void update(float dt) override;

    /// Additional utilities
    void setColor(sf::Color color);

    /// komentarz
    void addPoint(const sf::Vector2f& p);

    /// komentarz
    std::size_t getPointCount() const;

private:
    /// komentarz
    sf::VertexArray _vertices;

    /// komentarz
    std::vector<sf::Vector2f> _originalPoints;

    /// komentarz
    sf::Vector2f _origin;

    /// komentarz
    sf::Vector2f computeCentroid(const std::vector<sf::Vector2f>& pts) const;
    
    
    /// komentarz
    void rebuildVertexArray();
};
