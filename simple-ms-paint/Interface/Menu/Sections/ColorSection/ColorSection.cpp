#include "ColorSection.h"

#include "../../../../Button/ColorButton/ColorButton.h"

const int BUTTON_SIZE = 20;

ColorSection::ColorSection(float width, float height, Vector2f position)
	: MenuSection(width, height, position, {}) {
	loadColors();
}

void ColorSection::loadColors() {
	ColorButton* blackButton =
		new ColorButton(BUTTON_SIZE, ButtonState::enabled, ColorButtonType::black);
	buttons.emplace_back(blackButton);

	ColorButton* redButton =
		new ColorButton(BUTTON_SIZE, ButtonState::disabled, ColorButtonType::red);
	buttons.emplace_back(redButton);

	ColorButton* magentaButton =
		new ColorButton(BUTTON_SIZE, ButtonState::disabled, ColorButtonType::magenta);
	buttons.emplace_back(magentaButton);

	ColorButton* yellowButton =
		new ColorButton(BUTTON_SIZE, ButtonState::disabled, ColorButtonType::yellow);
	buttons.emplace_back(yellowButton);

	ColorButton* greenButton =
		new ColorButton(BUTTON_SIZE, ButtonState::disabled, ColorButtonType::green);
	buttons.emplace_back(greenButton);

	ColorButton* blueButton =
		new ColorButton(BUTTON_SIZE, ButtonState::disabled, ColorButtonType::blue);
	buttons.emplace_back(blueButton);

	positionButtons();
}

void ColorSection::positionButtons() {
	size_t numButtons = buttons.size();
	size_t buttonsPerRow = numButtons / 2;

	float horizontalSpacing = calculateHorizontalSpacing(numButtons, buttonsPerRow);
	float verticalSpacing = calculateVerticalSpacing();

	Vector2f buttonPosition = calculateInitialButtonPosition(horizontalSpacing, verticalSpacing);

	for (size_t i = 0; i < numButtons; ++i) {
		auto& button = buttons[i];

		if (isSecondRow(i, buttonsPerRow)) {
			adjustPositionForSecondRow(buttonPosition, i, horizontalSpacing, verticalSpacing, buttonsPerRow);
		}

		button->setPosition(buttonPosition);
		buttonPosition.x += BUTTON_SIZE + horizontalSpacing;
	}
}

float ColorSection::calculateHorizontalSpacing(size_t numButtons, size_t buttonsPerRow) const {
	return (section.getSize().x - BUTTON_SIZE * buttonsPerRow) / (buttonsPerRow + 1);
}

float ColorSection::calculateVerticalSpacing() const {
	return (section.getSize().y - BUTTON_SIZE * 2) / 3;
}

Vector2f ColorSection::calculateInitialButtonPosition(float horizontalSpacing, float verticalSpacing) const {
	return Vector2f(section.getPosition().x + horizontalSpacing, verticalSpacing);
}

bool ColorSection::isSecondRow(size_t index, size_t buttonsPerRow) const {
	return index >= buttonsPerRow;
}

void ColorSection::adjustPositionForSecondRow(Vector2f& buttonPosition, size_t index, float horizontalSpacing, float verticalSpacing, size_t buttonsPerRow) const {
	buttonPosition.x = section.getPosition().x + horizontalSpacing + (index - buttonsPerRow) * (BUTTON_SIZE + horizontalSpacing);
	buttonPosition.y = BUTTON_SIZE + 2 * verticalSpacing;
}

void ColorSection::drawTo(RenderWindow& window) {
	window.draw(section);

	for (auto& button : buttons) {
		button->drawTo(window);
	}
}