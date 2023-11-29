#pragma once

#include "../Button.h"

class ToolButton : public Button {
private:
	ToolButtonType type;

public:
	ToolButton();
	ToolButton(float size, Texture* texture, ButtonState state, ToolButtonType type);

	ToolButtonType getType() const;
	ButtonClass getButtonClass() const override;
};
