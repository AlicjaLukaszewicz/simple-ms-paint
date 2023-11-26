#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Canvas {
private:
	RectangleShape canvas;

public:
	Canvas(float width, float height, Vector2f position, float padding);
	void drawTo(RenderWindow& window);
};

