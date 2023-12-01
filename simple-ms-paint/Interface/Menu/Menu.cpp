#include "Menu.h"

Menu::Menu(float width, float height, Color color) {
	float colorSectionWidth = width / 3;
	float toolSectionWidth = 2 * width / 3;

	ToolSection* toolsSection =
		new ToolSection(toolSectionWidth, height, Vector2f(0, 0));
	ColorSection* colorsSection =
		new ColorSection(colorSectionWidth, height, Vector2f(toolSectionWidth, 0));

	menu.setSize(Vector2f(width, height));
	menu.setPosition(0, 0);
	menu.setFillColor(color);

	sections.emplace_back(toolsSection);
	sections.emplace_back(colorsSection);
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
		if (isMouseWithinSectionBounds(section, mousePosition)) {
			section->onMouseHover(mousePosition);
		}
	}
}

void Menu::onMouseClick(const Vector2f& mousePosition) {
	for (const auto& section : sections) {
		if (isMouseWithinSectionBounds(section, mousePosition)) {
			section->onMouseClick(mousePosition);
		}
	}
}

bool Menu::isMouseWithinSectionBounds(const MenuSection* section, const Vector2f& mousePosition) const {
	return section->getSection().getGlobalBounds().contains(mousePosition);
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