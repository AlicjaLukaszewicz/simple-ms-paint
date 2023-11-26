#include "Button.h"


Button::Button(string name, float width, float height, Texture* texture, ButtonState state)
    : name(name), width(width), height(height), state(state) {
    Texture* smoothTexture = texture;
    smoothTexture->setSmooth(true);

    button.setSize(Vector2f(width, height));

    buttonTexture.setSize(Vector2f(width, height));
    buttonTexture.setTexture(smoothTexture);

    setPosition(position);
}

void Button::setPosition(Vector2f position) {
    this->button.setPosition(position);
    this->buttonTexture.setPosition(position);
}

void Button::setState(ButtonState state) {
    this->state = state;
}

float Button::getWidth() {
    return width;
}

float Button::getHeight() {
    return height;
}

void Button::drawTo(RenderWindow& window) {
    if (state == ButtonState::enabled || state == ButtonState::hovered) {
        button.setFillColor(sf::Color(201, 224, 247));
        button.setOutlineThickness(1);
        button.setOutlineColor(Color(98, 162, 228));
    }
    else
        button.setFillColor(sf::Color(245, 246, 247));

    window.draw(button);
    window.draw(buttonTexture);
}