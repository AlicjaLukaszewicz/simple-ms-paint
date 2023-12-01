#pragma once

#include "../Button.h"

enum class ToolButtonType {
	pencil, bucket, eraser, colorpicker,
};

class ToolButton : public Button {
private:
	RectangleShape icon;
	ToolButtonType type;

public:
	ToolButton();
	ToolButton(float size, Texture* texture, ButtonState state, ToolButtonType type);

	void setPosition(Vector2f position) override;

	ToolButtonType getType() const;
	ButtonClass getButtonClass() const override;

	void drawTo(RenderWindow& window) override;
};
