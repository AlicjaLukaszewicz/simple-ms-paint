#include "Interface.h"

const Color MENU_BAR_COLOR = Color(245, 246, 247);

Interface::Interface(sf::RenderWindow& window)
	: menuBar(window.getSize().x, 70, MENU_BAR_COLOR),
	canvas(window.getSize().x, window.getSize().y - 70, Vector2f(0, 70), 40) {
}

void Interface::draw(RenderWindow& window) {
	menuBar.drawTo(window);
	canvas.drawTo(window);
}

void Interface::onMouseHover(RenderWindow& window, Vector2f mousePosition) {
	menuBar.onMouseHover(mousePosition);
}

void Interface::onMouseClick(RenderWindow& window, Vector2f mousePosition) {
	menuBar.onMouseClick(mousePosition);
}

void Interface::onMouseHold(RenderWindow& window, Vector2f mousePosition) {
	vector<Button*> enabledButtons = menuBar.getEnabledButtons();
	canvas.onMouseHold(mousePosition, enabledButtons);
}