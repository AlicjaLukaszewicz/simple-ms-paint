#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../../../Button/Button.h"
#include "../MenuSection.h"

using namespace sf;
using namespace std;

class ToolSection : public MenuSection {
public:
	ToolSection(float width, float height, Vector2f position);

	void loadTools();
	void positionButtons(float buttonSize);

	void drawTo(RenderWindow& window);
	void onMouseHover(const Vector2f& mousePosition);
	// bool onMouseClick(const Vector2f& mousePosition);
};
