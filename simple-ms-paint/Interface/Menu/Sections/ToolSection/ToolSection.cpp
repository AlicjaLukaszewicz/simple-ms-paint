#include "ToolSection.h"

#include "../../../../Button/ColorButton/ColorButton.h"
#include "../../../../Button/ToolButton/ToolButton.h"

const int BUTTON_SIZE = 40;

ToolSection::ToolSection(float width, float height, Vector2f position)
	: MenuSection(width, height, position, {}) {
	section.setFillColor(Color::Transparent);
	loadTools();
}

void ToolSection::loadTools() {
	Texture* pencilTexture = MenuSection::loadTexture("pencil.png");
	ToolButton* pencilButton =
		new ToolButton(BUTTON_SIZE, pencilTexture, ButtonState::enabled, ToolButtonType::pencil);
	buttons.emplace_back(pencilButton);

	Texture* eraserTexture = MenuSection::loadTexture("eraser.png");
	ToolButton* eraserButton =
		new ToolButton(BUTTON_SIZE, eraserTexture, ButtonState::disabled, ToolButtonType::eraser);
	buttons.emplace_back(eraserButton);

	Texture* bucketTexture = MenuSection::loadTexture("paint-bucket.png");
	ToolButton* bucketButton =
		new ToolButton(BUTTON_SIZE, bucketTexture, ButtonState::disabled, ToolButtonType::bucket);
	buttons.emplace_back(bucketButton);

	Texture* pipetteTexture = MenuSection::loadTexture("pipette.png");
	ToolButton* pipetteButton =
		new ToolButton(BUTTON_SIZE, pipetteTexture, ButtonState::disabled, ToolButtonType::colorpicker);
	buttons.emplace_back(pipetteButton);

	positionButtons();
}

void ToolSection::positionButtons() {
	float centerY = section.getPosition().y + section.getSize().y / 2.0f;
	size_t numButtons = buttons.size();

	float horizontalSpacing = (section.getSize().x - BUTTON_SIZE) / (numButtons + 1);

	Vector2f buttonPosition(horizontalSpacing, (section.getSize().y - BUTTON_SIZE) / 2.0f);

	for (auto& button : this->buttons) {
		button->setPosition(buttonPosition);
		buttonPosition.x += BUTTON_SIZE + horizontalSpacing;
	}
}

void ToolSection::drawTo(RenderWindow& window) {
	window.draw(section);

	for (auto& button : buttons) {
		button->drawTo(window);
	}
}