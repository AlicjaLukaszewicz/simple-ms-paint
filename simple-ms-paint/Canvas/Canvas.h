#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"

using namespace sf;

class Canvas {
private:
	RectangleShape canvas;
	VertexArray pixels;

public:
	Canvas(float width, float height, Vector2f position, float padding);
	void draw(RectangleShape pixel);
	void drawTo(RenderWindow& window);

	void onMouseHold(Vector2f mousePosition, Button enabledButton);
};

