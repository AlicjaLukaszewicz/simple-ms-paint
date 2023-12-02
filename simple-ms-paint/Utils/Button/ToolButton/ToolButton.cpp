#include "ToolButton.h"

ToolButton::ToolButton(float size, Texture* texture, ButtonState state, ToolButtonType type)
	: Button(size, state), type(type) {
	Texture* smoothTexture = texture;
	smoothTexture->setSmooth(true);

	icon.setSize(Vector2f(size, size));
	icon.setTexture(smoothTexture);
}

void ToolButton::setPosition(Vector2f position) {
	button.setPosition(position);
	icon.setPosition(position);
}

void ToolButton::drawTo(RenderWindow& window) {
	setButtonStyle();

	window.draw(button);
	window.draw(icon);
}

ToolButton::ToolButton() {
	size = 1.0;
	type = ToolButtonType::pencil;
	state = ButtonState::disabled;
}

ToolButtonType ToolButton::getType() const {
	return type;
}

ButtonClass ToolButton::getButtonClass() const {
	return ButtonClass::tool;
}