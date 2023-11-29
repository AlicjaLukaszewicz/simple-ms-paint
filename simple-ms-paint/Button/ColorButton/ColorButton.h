#pragma once

#include "../Button.h"

class ColorButton : public Button {
private:
	ColorButtonType type;
	ButtonClass getButtonClass() const;

public:
	ColorButton();
	ColorButton(float size, Texture* texture, ButtonState state, ColorButtonType type);
	Color getColor();
};
