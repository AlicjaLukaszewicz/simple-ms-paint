#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Button/Button.h"

using namespace sf;
using namespace std;

class Interface {
private:
	vector<Button> buttons;
	RectangleShape menuBar;
	RectangleShape canvas;

public:
	Interface(RenderWindow& window);

	void draw(RenderWindow& window);
	void createMenuBar(float width, float height, vector<Button> buttons, Color Color);
	void createCanvas(float width, float height, Vector2f position);

	vector<Button> loadButtons();
	Texture* loadTexture(const string& filename);
};