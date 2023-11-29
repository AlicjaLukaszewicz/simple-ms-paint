#include "ColorButton.h"

ColorButton::ColorButton(float size, Texture* texture, ButtonState state, ColorButtonType type)
	: Button(size, texture, state), type(type) {
}

ColorButton::ColorButton() {
	int a = 1;
}

ButtonClass ColorButton::getButtonClass() const {
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