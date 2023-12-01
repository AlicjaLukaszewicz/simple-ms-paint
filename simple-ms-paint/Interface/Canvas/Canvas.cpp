#include "Canvas.h"

const float PIXEL_SIZE = 5.0f;

Canvas::Canvas(float width, float height, Vector2f position, float padding)
	: canvasPosition(position.x + padding, position.y + padding),
	pixelSize(PIXEL_SIZE),
	pixels(nullptr) {
	canvasSize = { width - 2 * padding, height - 2 * padding };

	canvas.setSize(canvasSize);
	canvas.setPosition(canvasPosition);
	canvas.setFillColor(Color::White);

	initializePixels(width, height);
}

void Canvas::drawTo(RenderWindow& window) {
	window.draw(canvas);
	window.draw(*pixels);
}

void Canvas::onMouseHold(Vector2f mousePosition, vector<Button*> enabledButtons) {
	ColorButton* colorButton = findColorButton(enabledButtons);
	ToolButton* toolButton = findToolButton(enabledButtons);

	if (colorButton == nullptr || toolButton == nullptr) {
		// Handle the case where colorButton or toolButton is not found
		// return;
	}

	Color color = colorButton->getColor();

	if (toolButton->getType() == ToolButtonType::pencil) {
		handlePencilAction(mousePosition, color);
	}
	else if (toolButton->getType() == ToolButtonType::eraser) {
		handleEraserAction(mousePosition);
	}
}

void Canvas::handlePencilAction(Vector2f mousePosition, const Color& color) {
	updateCanvasPixels(mousePosition, color);
}

void Canvas::handleEraserAction(Vector2f mousePosition) {
	updateCanvasPixels(mousePosition, canvas.getFillColor());
}

void Canvas::initializePixels(float width, float height) {
	pixels = new VertexArray(Points, static_cast<std::size_t>(width * height));
}

ColorButton* Canvas::findColorButton(const vector<Button*>& buttons) const {
	for (auto& button : buttons) {
		if (button->getButtonClass() == ButtonClass::color) {
			return static_cast<ColorButton*>(button);
		}
	}
	return nullptr;
}

ToolButton* Canvas::findToolButton(const vector<Button*>& buttons) const {
	for (auto& button : buttons) {
		if (button->getButtonClass() == ButtonClass::tool) {
			return static_cast<ToolButton*>(button);
		}
	}
	return nullptr;
}

void Canvas::updateCanvasPixels(Vector2f mousePosition, const Color& newColor) {
	size_t index = 0;

	for (float i = -pixelSize / 2; i <= pixelSize / 2; ++i) {
		for (float j = -pixelSize / 2; j <= pixelSize / 2; ++j) {
			if (isModifiedPositionOnCanvas(mousePosition, i, j)) {
				index = calculateIndex(mousePosition, i, j);

				(*pixels)[index].position = mousePosition + Vector2f(i, j);
				(*pixels)[index].color = newColor;
			}
		}
	}
}

bool Canvas::isMouseOnCanvas(Vector2f mousePosition) const {
	FloatRect canvasBounds = canvas.getGlobalBounds();
	return canvasBounds.contains(mousePosition);
}

bool Canvas::isModifiedPositionOnCanvas(Vector2f mousePosition, float i, float j) const {
	FloatRect canvasBounds = canvas.getGlobalBounds();
	return canvasBounds.contains(mousePosition.x + i, mousePosition.y + j);
}

size_t Canvas::calculateIndex(Vector2f mousePosition, float i, float j) const {
	return static_cast<size_t>((mousePosition.x + i - canvas.getPosition().x) +
		(mousePosition.y + j - canvas.getPosition().y) * canvas.getSize().x);
}

Canvas::~Canvas() {
	delete pixels;
}