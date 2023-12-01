#include "CurrentColorDisplay.h"

#include <iostream>

CurrentColorDisplay::CurrentColorDisplay() {
	size = 0;
	display.setSize({ 0, 0 });
	display.setFillColor(Color::Black);
}

RectangleShape CurrentColorDisplay::getDisplay() const
{
	return display;
}

void CurrentColorDisplay::setSize(float size)
{
	display.setSize({ size, size });
}

void CurrentColorDisplay::setPosition(Vector2f position)
{
	display.setPosition(position);
}

void CurrentColorDisplay::setColor(Color color)
{
	display.setFillColor(color);
}

void CurrentColorDisplay::drawTo(RenderWindow& window) {
	window.draw(display);
}