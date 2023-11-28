#include "ToolSection.h"

ToolSection::ToolSection(float width, float height, Vector2f position)
	: MenuSection(width, height, position, {}) {
	section.setFillColor(Color::Transparent);
	loadTools();
}

void ToolSection::loadTools() {
	const float buttonSize = 40;

	Texture* pencilTexture = MenuSection::loadTexture("pencil.png");
	ToolButton* pencilButton = new ToolButton(buttonSize, pencilTexture, ButtonState::enabled, ToolButtonType::pencil);
	buttons.emplace_back(pencilButton);

	Texture* eraserTexture = MenuSection::loadTexture("eraser.png");
	ToolButton* eraserButton = new ToolButton(buttonSize, eraserTexture, ButtonState::disabled, ToolButtonType::eraser);
	buttons.emplace_back(eraserButton);

	Texture* bucketTexture = MenuSection::loadTexture("paint-bucket.png");
	ToolButton* bucketButton = new ToolButton(buttonSize, bucketTexture, ButtonState::disabled, ToolButtonType::bucket);
	buttons.emplace_back(bucketButton);

	Texture* pipetteTexture = MenuSection::loadTexture("pipette.png");
	ToolButton* pipetteButton = new ToolButton(buttonSize, pipetteTexture, ButtonState::disabled, ToolButtonType::colorpicker);
	buttons.emplace_back(pipetteButton);

	positionButtons(buttonSize);
}

void ToolSection::positionButtons(float buttonSize) {
	float centerY = section.getPosition().y + section.getSize().y / 2.0f;
	size_t numButtons = buttons.size();

	float horizontalSpacing = (section.getSize().x - buttonSize) / (numButtons + 1);

	Vector2f buttonPosition(horizontalSpacing, (section.getSize().y - buttonSize) / 2.0f);

	for (auto& button : this->buttons) {
		button->setPosition(buttonPosition);
		buttonPosition.x += buttonSize + horizontalSpacing;
	}
}

void ToolSection::drawTo(RenderWindow& window) {
	window.draw(section);

	for (auto& button : buttons) {
		button->drawTo(window);
	}
}

void ToolSection::onMouseHover(const Vector2f& mousePosition) {
	MenuSection::onMouseHover(mousePosition);
}