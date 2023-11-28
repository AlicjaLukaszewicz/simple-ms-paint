#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "MenuBar/MenuBar.h"
#include "Canvas/Canvas.h"

using namespace sf;
using namespace std;

class Interface {
private:
	MenuBar menuBar;
	Canvas canvas;

public:
	Interface(RenderWindow& window);

	void draw(RenderWindow& window);

	void onMouseHover(RenderWindow& window, Vector2f mousePosition);
	void onMouseClick(RenderWindow& window, Vector2f mousePosition);
	void onMouseHold(RenderWindow& window, Vector2f mousePosition);
};