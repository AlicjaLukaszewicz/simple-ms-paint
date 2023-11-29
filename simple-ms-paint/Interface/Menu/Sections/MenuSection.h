#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../../Button/Button.h"

using namespace sf;
using namespace std;

class MenuSection {
protected:
	RectangleShape section;
	vector<Button*> buttons;

public:
	MenuSection(float width, float height, Vector2f position, vector<Button*> buttons);
	~MenuSection();

	Vector2f getSize();
	vector<Button*> getButtons();

	void setSize(float width, float height);
	void setPosition(Vector2f position);
	void setFillColor(Color color);

	Texture* loadTexture(const string& filename);

	virtual void positionButtons();
	virtual void drawTo(RenderWindow& window);
	virtual void onMouseHover(const Vector2f& mousePosition);
};
