#include "MenuSection.h"

const string FILE_PATH = "Resources/";

MenuSection::MenuSection(float width, float height, Vector2f position, vector<Button*> buttons)
	: buttons(buttons) {
	section.setFillColor(Color::Transparent);
	section.setSize(Vector2f(width, height));
	section.setPosition(position);
}

MenuSection::~MenuSection()
{
	for (Button* button : buttons) {
		delete button;
	}
}

Vector2f MenuSection::getSize()
{
	return section.getSize();
}

vector<Button*> MenuSection::getButtons()
{
	return buttons;
}

RectangleShape MenuSection::getSection() const
{
	return section;
}

void MenuSection::setSize(float width, float height)
{
	section.setSize(Vector2f(width, height));
}

void MenuSection::setPosition(Vector2f position)
{
	section.setPosition(position);
}

void MenuSection::setFillColor(Color color)
{
	section.setFillColor(color);
}

Texture* MenuSection::loadTexture(const string& filename) {
	Texture* texture = new Texture();
	if (!texture->loadFromFile(FILE_PATH + filename)) {
		cerr << "Failed to load texture: " << FILE_PATH + filename << endl;
	}

	return texture;
}

void MenuSection::onMouseHover(const Vector2f& mousePosition) {
}

void MenuSection::onMouseClick(const Vector2f& mousePosition) {
	for (auto& button : buttons) {
		if (button->getButtonShape().getGlobalBounds().contains(mousePosition)) {
			button->setState(ButtonState::enabled);
			setOtherButtonsToDisabled(button);
		}
	}
}

void MenuSection::setOtherButtonsToDisabled(const Button* clickedButton) {
	for (const auto& button : buttons) {
		if (button != clickedButton) {
			button->setState(ButtonState::disabled);
		}
	}
}

void MenuSection::positionButtons() {
}

void MenuSection::drawTo(RenderWindow& window) {
	window.draw(section);

	for (auto& button : buttons) {
		button->drawTo(window);
	}
}