#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../../../Button/Button.h"
#include "../MenuSection.h"

using namespace sf;
using namespace std;

class ColorSection : public MenuSection {
private:
	void loadColors();

	float calculateHorizontalSpacing(size_t numButtons, size_t buttonsPerRow) const;
	float calculateVerticalSpacing() const;
	Vector2f calculateInitialButtonPosition(float horizontalSpacing, float verticalSpacing) const;

	bool isSecondRow(size_t index, size_t buttonsPerRow) const;
	void adjustPositionForSecondRow(Vector2f& buttonPosition, size_t index, float horizontalSpacing, float verticalSpacing, size_t buttonsPerRow) const;

public:
	ColorSection(float width, float height, Vector2f position);

	void positionButtons() override;
	void drawTo(RenderWindow& window) override;
};
