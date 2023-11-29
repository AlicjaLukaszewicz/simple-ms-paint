#include "Menu.h"

Menu::Menu(float width, float height, Color color) {
	ToolSection* toolsSection = new ToolSection(width / 3, height, Vector2f(0, 0));

	menu.setSize(Vector2f(width, height));
	menu.setPosition(0, 0);
	menu.setFillColor(color);

	sections.emplace_back(toolsSection);
}

Menu::~Menu()
{
	for (MenuSection* section : sections) {
		delete section;
	}
}

void Menu::drawTo(RenderWindow& window) {
	window.draw(menu);

	float currentX = 0.0f;
	for (auto& section : sections) {
		section->drawTo(window);
		currentX += section->getSize().x;
	}
}

void Menu::onMouseHover(const Vector2f& mousePosition) {
	for (const auto& section : sections) {
		handleButtonHover(section->getButtons(), mousePosition);
	}
}

void Menu::onMouseClick(const Vector2f& mousePosition) {
	for (auto& section : sections) {
		handleButtonClick(section->getButtons(), mousePosition);
	}
}

void Menu::handleButtonClick(const vector<Button*>& buttons, const Vector2f& mousePosition) {
	for (auto& button : buttons) {
		if (button->isMouseOver(mousePosition) && button->getState() == ButtonState::disabled) {
			button->setState(ButtonState::enabled);
			setOtherButtonsToDisabled(buttons, button);
		}
	}
}

void Menu::handleButtonHover(const vector<Button*>& buttons, const Vector2f& mousePosition) {
	for (auto& button : buttons) {
		button->setIsHovered(button->isMouseOver(mousePosition));
	}
}

vector<Button*> Menu::getEnabledButtons() const {
	vector<Button*> enabledButtons;

	for (const auto& section : sections) {
		for (const auto& button : section->getButtons()) {
			if (button->getState() == ButtonState::enabled) {
				enabledButtons.emplace_back(button);
			}
		}
	}

	return enabledButtons;
}

void Menu::setOtherButtonsToDisabled(const vector<Button*> buttons, const Button* clickedButton) {
	for (const auto& button : buttons) {
		if (button != clickedButton) {
			button->setState(ButtonState::disabled);
		}
	}
}