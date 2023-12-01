#include "Button.h"

Button::Button(float size, ButtonState state)
	: state(state), isHovered(false) {
	button.setSize(Vector2f(size, size));
	setPosition(position);
}

Button::Button() {
	isHovered = false;
	size = 0;
	state = ButtonState::disabled;
}

ButtonClass Button::getButtonClass() const {
	return ButtonClass::none;
}

void Button::setPosition(Vector2f position) {
	button.setPosition(position);
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
	setButtonStyle();

	window.draw(button);
}

void Button::setButtonStyle() {
	button.setOutlineColor(Color(98, 162, 228));

	if (state == ButtonState::enabled || isHovered) {
		button.setFillColor(sf::Color(201, 224, 247));
		button.setOutlineThickness(1);
	}
	else {
		button.setFillColor(sf::Color(245, 246, 247));
		button.setOutlineThickness(0);
	}
}

bool Button::isMouseOver(Vector2f mousePosition) {
	return button.getGlobalBounds().contains(mousePosition);
}

ButtonState Button::getState() const {
	return state;
}

RectangleShape Button::getButtonShape() const
{
	return button;
}