#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Menu/Menu.h"
#include "Canvas/Canvas.h"

using namespace sf;
using namespace std;

class Interface {
private:
	Menu* menu;
	Canvas* canvas;

public:
	Interface(RenderWindow& window);
	~Interface();

	void draw(RenderWindow& window);

	void onMouseHover(RenderWindow& window, Vector2f mousePosition);
	void onMouseClick(RenderWindow& window, Vector2f mousePosition);
	void onMouseHold(RenderWindow& window, Vector2f mousePosition);
};
