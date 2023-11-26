#include "Canvas.h"

Canvas::Canvas(float width, float height, sf::Vector2f position, float padding) {
    canvas.setSize(sf::Vector2f(width - 2 * padding, height - 2 * padding));
    canvas.setPosition(position.x + padding, position.y + padding);
    canvas.setFillColor(sf::Color::White);
}

void Canvas::drawTo(sf::RenderWindow& window) {
    window.draw(canvas);
}