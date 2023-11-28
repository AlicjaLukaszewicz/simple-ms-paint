#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class ButtonClass {
	tool, color, none
};

enum class ButtonState
{
	enabled, disabled
};

enum class ToolButtonType {
	pencil, bucket, eraser, colorpicker,
};

enum class ColorButtonType {
	red,
	yellow,
	green,
	blue,
	black
};

class Button {
protected:
	RectangleShape button;
	RectangleShape buttonTexture;

	float size;
	Vector2f position;

	Color color;
	ButtonState state;
	bool isHovered;

public:
	Button();
	Button(float size, Texture* texture, ButtonState state);

	void setPosition(Vector2f position);
	void setState(ButtonState state);

	void setIsHovered(bool isHovered);
	bool getIsHovered() const;

	float getSize();
	ButtonState getState();

	void drawTo(RenderWindow& window);
	bool isMouseOver(Vector2f mousePosition);

	virtual ButtonClass getButtonClass();
};

class ToolButton : public Button {
private:
	ToolButtonType type;
	ButtonClass getButtonClass();

public:
	ToolButton();
	ToolButton(float size, Texture* texture, ButtonState state, ToolButtonType type);

	ToolButtonType getType();
};

class ColorButton : public Button {
private:
	ColorButtonType type;
	ButtonClass getButtonClass();

public:
	ColorButton();
	ColorButton(float size, Texture* texture, ButtonState state, ColorButtonType type);
	Color getColor();
};

#endif
