#include "ColorSection.h"

#include "../../../../Button/ColorButton/ColorButton.h"

const int BUTTON_SIZE = 20;
const int NUMBER_OF_ROWS = 2;

ColorSection::ColorSection(float width, float height, Vector2f position)
	: MenuSection(width, height, position, {}) {
	currentColorDisplay = new CurrentColorDisplay();
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
	int numButtons = buttons.size();
	int buttonsPerRow = numButtons / NUMBER_OF_ROWS;

	// Calculate vertical spacing
	float verticalSpacing = calculateVerticalSpacing();

	float currentColorDisplaySize = verticalSpacing + NUMBER_OF_ROWS * BUTTON_SIZE;
	currentColorDisplay->setSize(currentColorDisplaySize);

	float currectColorDisplayY = section.getPosition().y + (section.getSize().y - currentColorDisplaySize) / 2;

	// Calculate horizontal spacing
	float horizontalSpacing = calculateHorizontalSpacing(currentColorDisplaySize, buttonsPerRow);

	float currentColorDisplayX = section.getPosition().x + horizontalSpacing;
	currentColorDisplay->setPosition({ currentColorDisplayX, currectColorDisplayY });

	// Setup buttons position
	float startButtonX = section.getPosition().x + 2 * horizontalSpacing + currentColorDisplaySize;
	float startButtonY = section.getPosition().y + verticalSpacing;
	float buttonTopX = startButtonX;
	float buttonBottomX = startButtonX;
	float buttonTopY = startButtonY;
	float buttonBottomY = startButtonY + verticalSpacing + BUTTON_SIZE;

	for (int i = 0; i < numButtons; i++)
	{
		if (i < buttonsPerRow) {
			buttonTopX += (verticalSpacing + BUTTON_SIZE);
			buttons[i]->setPosition({ buttonTopX, buttonTopY });
		}
		else
		{
			buttonBottomX += (verticalSpacing + BUTTON_SIZE);
			buttons[i]->setPosition({ buttonBottomX, buttonBottomY });
		}
	}
}

float ColorSection::calculateVerticalSpacing() {
	return (section.getSize().y - NUMBER_OF_ROWS * BUTTON_SIZE) / (NUMBER_OF_ROWS + 1);
}

float ColorSection::calculateHorizontalSpacing(float currentColorDisplaySize, int buttonsPerRow) {
	return (section.getSize().x - currentColorDisplaySize - buttonsPerRow * BUTTON_SIZE) / (buttonsPerRow + 2);
}

void ColorSection::drawTo(RenderWindow& window) {
	window.draw(section);
	currentColorDisplay->drawTo(window);

	for (auto& button : buttons) {
		button->drawTo(window);
	}
}

void ColorSection::onMouseClick(const Vector2f& mousePosition)
{
	Color color;
	for (auto& button : buttons) {
		if (button->getButtonShape().getGlobalBounds().contains(mousePosition)) {
			button->setState(ButtonState::enabled);
			setOtherButtonsToDisabled(button);
			ColorButton* colorButton = dynamic_cast<ColorButton*>(button);
			color = colorButton->getColor();
		}
	}
	currentColorDisplay->setColor(color);
}

Color ColorSection::getPickedColor() const {
	for (auto& button : buttons) {
		if (button->getState() == ButtonState::enabled) {
			ColorButton* colorButton = dynamic_cast<ColorButton*>(button);
			if (colorButton) {
				return colorButton->getColor();
			}
		}
	}

	return Color::White;
}