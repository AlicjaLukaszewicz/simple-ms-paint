#include "Button.h"

Button::Button(float size, Texture* texture, ButtonState state)
	: state(state), isHovered(false) {
	Texture* smoothTexture = texture;
	smoothTexture->setSmooth(true);

	button.setSize(Vector2f(size, size));

	buttonTexture.setSize(Vector2f(size, size));
	buttonTexture.setTexture(smoothTexture);

	setPosition(position);
}

Button::Button() {
	state = ButtonState::disabled;
}

ButtonClass Button::getButtonClass() const {
	return ButtonClass::none;
}

void Button::setPosition(Vector2f position) {
	button.setPosition(position);
	buttonTexture.setPosition(position);
}

void Button::setState(ButtonState state) {
	this->state = state;
}

void Button::setIsHovered(bool isHovered) {
	this->isHovered = isHovered;
}

bool Button::getIsHovered() const {
	return isHovered;
}

float Button::getSize() const {
	return button.getSize().x;
}

void Button::drawTo(RenderWindow& window) {
	button.setOutlineColor(Color(98, 162, 228));

	if (state == ButtonState::enabled || isHovered) {
		button.setFillColor(sf::Color(201, 224, 247));
		button.setOutlineThickness(1);
	}
	else {
		button.setFillColor(sf::Color(245, 246, 247));
		button.setOutlineThickness(0);
	}

	window.draw(button);
	window.draw(buttonTexture);
}

bool Button::isMouseOver(Vector2f mousePosition) {
	return button.getGlobalBounds().contains(mousePosition);
}

ButtonState Button::getState() const {
	return state;
}