#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../../../Utils/Button/Button.h"
#include "../MenuSection.h"
#include "CurrentColorDisplay/CurrentColorDisplay.h"
#include "../../../../Observer/Observer.h"

using namespace sf;
using namespace std;

class ColorSection : public MenuSection, public Observer {
private:
	CurrentColorDisplay* currentColorDisplay;

	void loadColors();

	void updateColor(const Color& color) override;

	float calculateVerticalSpacing();
	float calculateHorizontalSpacing(float currentColorDisplaySize, int buttonsPerRow);
public:
	ColorSection(float width, float height, Vector2f position);

	Color getPickedColor() const;

	void positionButtons() override;
	void drawTo(RenderWindow& window) override;

	void onMouseClick(const Vector2f& mousePosition) override;
};
