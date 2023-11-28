#include "Button.h"

Button::Button(float size, Texture* texture, ButtonState state)
	: state(state) {
	isHovered = false;
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

ButtonClass Button::getButtonClass() {
	return ButtonClass::none;
}

void Button::setPosition(Vector2f position) {
	this->button.setPosition(position);
	this->buttonTexture.setPosition(position);
}

void Button::setState(ButtonState state) {
	this->state = state;
}

void Button::setIsHovered(bool isHovered)
{
	this->isHovered = isHovered;
}

bool Button::getIsHovered() const
{
	return isHovered;
}

float Button::getSize() {
	return size;
}

void Button::drawTo(RenderWindow& window) {
	button.setOutlineColor(Color(98, 162, 228));

	if (state == ButtonState::enabled || getIsHovered()) {
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

ButtonState Button::getState() {
	return state;
}

ToolButton::ToolButton(float size, Texture* texture, ButtonState state, ToolButtonType type)
	: Button(size, texture, state), type(type) {
}

ToolButton::ToolButton() {
	size = 1.0;
	type = ToolButtonType::pencil;
	state = ButtonState::disabled;
}

ButtonClass ToolButton::getButtonClass() {
	return ButtonClass::tool;
}

ToolButtonType ToolButton::getType()
{
	return type;
}

ColorButton::ColorButton(float size, Texture* texture, ButtonState state, ColorButtonType type)
	: Button(size, texture, state), type(type) {
}

ColorButton::ColorButton() {
	int a = 1;
}

ButtonClass ColorButton::getButtonClass() {
	return ButtonClass::color;
}

Color ColorButton::getColor()
{
	switch (type)
	{
	case ColorButtonType::red:
		return Color::Red;
	case ColorButtonType::yellow:
		return Color::Yellow;
	case ColorButtonType::green:
		return Color::Green;
	case ColorButtonType::blue:
		return Color::Blue;
	case ColorButtonType::black:
		return Color::Black;
	default:
		return Color::White;
	}
}