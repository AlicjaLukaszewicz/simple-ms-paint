#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../../../Utils/Button/Button.h"
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

	void onMouseHover(const Vector2f& mousePosition) override;
};
