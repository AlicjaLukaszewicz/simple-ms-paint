#include "MenuBar.h"

MenuBar::MenuBar(float width, float height, Color color)
	: toolsSection(width / 3, height, Vector2f(0, 0)) {
	menuBar.setSize(Vector2f(width, height));
	menuBar.setPosition(0, 0);
	menuBar.setFillColor(color);

	sections.emplace_back(toolsSection);
}

void MenuBar::drawTo(RenderWindow& window) {
	window.draw(menuBar);

	float currentX = 0.0f;
	for (auto& section : sections) {
		section.drawTo(window);
		currentX += section.getSize().x;
	}
}

bool MenuBar::onMouseHover(const Vector2f& mousePosition) {
	for (auto& section : this->sections) {
		vector<Button*> buttons = section.getButtons();
		for (auto& button : buttons) {
			button->setIsHovered(button->isMouseOver(mousePosition));
		}
	}
	return true;
}

bool MenuBar::onMouseClick(const Vector2f& mousePosition) {
	bool isButtonClicked = false;

	for (auto& section : this->sections) {
		vector<Button*> buttons = section.getButtons();

		for (auto& button : buttons) {
			if (button->isMouseOver(mousePosition)) {
				if (button->getState() == ButtonState::disabled) {
					button->setState(ButtonState::enabled);
					setOtherButtonsToDisabled(buttons, button);
				}

				isButtonClicked = true;
			}
		}
	}

	return isButtonClicked;
}

vector<Button*> MenuBar::getEnabledButtons()
{
	vector<Button*> enabledButtons;

	for (auto& section : this->sections) {
		vector<Button*> buttons = section.getButtons();

		for (auto& button : buttons) {
			if (button->getState() == ButtonState::enabled)
				enabledButtons.emplace_back(button);
		}
	}
	return enabledButtons;
}

void MenuBar::setOtherButtonsToDisabled(vector<Button*> buttons, const Button* clickedButton) {
	for (auto& button : buttons) {
		if (button != clickedButton) {
			button->setState(ButtonState::disabled);
		}
	}
}