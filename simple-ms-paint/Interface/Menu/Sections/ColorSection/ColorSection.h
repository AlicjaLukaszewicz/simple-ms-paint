#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../MenuSection.h"

using namespace sf;
using namespace std;

class ColorPalette : MenuSection {
public:
	ColorPalette(Vector2f position);
	void draw(RenderWindow& window);
};
