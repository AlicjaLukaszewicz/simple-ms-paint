#pragma once

#include "../Button.h"

enum class ColorButtonType {
	black,
	red,
	magenta,
	yellow,
	green,
	blue
};

class ColorButton : public Button {
private:
	ColorButtonType type;
	ButtonClass getButtonClass() const;

public:
	ColorButton();
	ColorButton(float size, ButtonState state, ColorButtonType type);
	ColorButtonType getColorButtonType() const;
	Color getColor() const;

	void drawTo(RenderWindow& window) override;
};
