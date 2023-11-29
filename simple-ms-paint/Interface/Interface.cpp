#include "Interface.h"

const Color MENU_COLOR = Color(245, 246, 247);
const int MENU_HEIGHT = 70;
const int CANVAS_PADDING = 40;

Interface::Interface(RenderWindow& window) {
	menu = new Menu(window.getSize().x, MENU_HEIGHT, MENU_COLOR);
	canvas = new Canvas(window.getSize().x, window.getSize().y - MENU_HEIGHT,
		Vector2f(0, MENU_HEIGHT), CANVAS_PADDING);
}

Interface::~Interface()
{
	delete menu;
	delete canvas;
}

void Interface::draw(RenderWindow& window) {
	menu->drawTo(window);
	canvas->drawTo(window);
}

void Interface::onMouseHover(RenderWindow& window, Vector2f mousePosition) {
	menu->onMouseHover(mousePosition);
}

void Interface::onMouseClick(RenderWindow& window, Vector2f mousePosition) {
	menu->onMouseClick(mousePosition);
}

void Interface::onMouseHold(RenderWindow& window, Vector2f mousePosition) {
	vector<Button*> enabledButtons = menu->getEnabledButtons();
	canvas->onMouseHold(mousePosition, enabledButtons);
}