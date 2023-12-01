#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class ButtonClass {
	tool, color, none
};

enum class ButtonState {
	enabled, disabled
};

class Button {
protected:
	RectangleShape button;

	float size;
	Vector2f position;

	Color color;
	ButtonState state;
	bool isHovered;

public:
	Button();
	Button(float size, ButtonState state);

	void setState(ButtonState state);
	void setIsHovered(bool isHovered);
	void setButtonStyle();
	virtual void setPosition(Vector2f position);

	float getSize() const;
	bool getIsHovered() const;
	ButtonState getState() const;
	virtual ButtonClass getButtonClass() const = 0;

	virtual void drawTo(RenderWindow& window);
	bool isMouseOver(Vector2f mousePosition);
};
#endif
