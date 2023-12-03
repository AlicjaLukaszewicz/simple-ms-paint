#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class CurrentColorDisplay
{
private:
	RectangleShape display;

	float size;
	Vector2f position;

public:
	CurrentColorDisplay();

	RectangleShape getDisplay() const;

	void setSize(float size);
	void setPosition(Vector2f position);
	void updateColor(Color color);

	void drawTo(RenderWindow& window);
};
