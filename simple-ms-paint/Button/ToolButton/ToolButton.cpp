#include "ToolButton.h"

ToolButton::ToolButton(float size, Texture* texture, ButtonState state, ToolButtonType type)
	: Button(size, texture, state), type(type) {
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