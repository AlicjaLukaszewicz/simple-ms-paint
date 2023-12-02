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

	Canvas* getCanvas();

	void draw(RenderWindow& window);

	void onMouseHover(RenderWindow& window);
	void onMouseClick(RenderWindow& window);
	void onMouseHold(RenderWindow& window);
};
