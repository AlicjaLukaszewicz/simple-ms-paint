#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../../../Button/Button.h"
#include "../MenuSection.h"

using namespace sf;
using namespace std;

class ToolSection : public MenuSection {
private:
	void loadTools();

public:
	ToolSection(float width, float height, Vector2f position);

	void positionButtons() override;
	void drawTo(RenderWindow& window) override;
};
