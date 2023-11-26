#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class ButtonState
{
	enabled, disabled
};

enum class ButtonFunction {
	pencil, bucket, eraser, colorpicker
};

class Button {
private:
	RectangleShape button;
	RectangleShape buttonTexture;

	float width;
	float height;
	Vector2f position;

	Color color;
	ButtonState state;
	ButtonFunction function;
	bool isHovered;

public:
	Button();
	Button(float width, float height, Texture* texture, ButtonState state, ButtonFunction function);
	void setPosition(Vector2f position);
	void setState(ButtonState state);

	void setIsHovered(bool isHovered);
	bool getIsHovered() const;

	float getWidth();
	float getHeight();
	ButtonState getState();
	ButtonFunction getFunction();

	void drawTo(RenderWindow& window);
	bool isMouseOver(Vector2f mousePosition);
};

#endif 