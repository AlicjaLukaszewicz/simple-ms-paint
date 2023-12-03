#include "Canvas.h"
#include "../../Utils/Tool/ColorPicker/ColorPicker.h"
#include "../../Utils/Tool/Pencil/Pencil.h"
#include "../../Utils/Tool/Eraser/Eraser.h"
#include "../../Utils/Tool/Fill/Fill.h"

Canvas::Canvas(float width, float height, Vector2f position, float padding)
	: pixels(nullptr) {
	canvasPosition = { position.x + padding, position.y + padding };
	canvasSize = { width - 2 * padding, height - 2 * padding };
	previousMousePosition = { 0, 0 };

	canvas.setSize(canvasSize);
	canvas.setPosition(canvasPosition);
	canvas.setFillColor(Color::White);

	initializePixels(canvasSize.x, canvasSize.y);
}

Vector2i Canvas::getPreviousMousePosition() const {
	return previousMousePosition;
}

VertexArray* Canvas::getPixels() const {
	return pixels;
}

Vector2f Canvas::getPosition() const {
	return canvasPosition;
}

Vector2f Canvas::getSize() const {
	return canvasSize;
}

Color Canvas::getFillColor() const
{
	return canvas.getFillColor();
}

void Canvas::setPreviousMousePosition(Vector2i previousMousePosition) {
	this->previousMousePosition = previousMousePosition;
}

void Canvas::drawTo(RenderWindow& window) {
	window.draw(canvas);
	window.draw(*pixels);
}

void Canvas::onMouseHold(RenderWindow& window, vector<Button*> enabledButtons) {
	ColorButton* colorButton = findColorButton(enabledButtons);
	ToolButton* toolButton = findToolButton(enabledButtons);

	if (!colorButton || !toolButton) {
		return;
	}

	Color color = colorButton->getColor();

	if (toolButton->getType() == ToolButtonType::pencil) {
		Pencil::draw(*this, window, color);
	}
	else if (toolButton->getType() == ToolButtonType::eraser) {
		Eraser::erase(*this, window);
	}
}

void Canvas::onMouseClick(RenderWindow& window, vector<Button*> enabledButtons) {
	ColorButton* colorButton = findColorButton(enabledButtons);
	ToolButton* toolButton = findToolButton(enabledButtons);

	if (!colorButton || !toolButton) {
		return;
	}

	Color color = colorButton->getColor();

	if (toolButton->getType() == ToolButtonType::bucket) {
		Fill::fill(*this, window, color);
	}
	else if (toolButton->getType() == ToolButtonType::colorpicker) {
		ColorPicker::pick(*this, window);
	}
}

void Canvas::initializePixels(float width, float height) {
	pixels = new VertexArray(Points, static_cast<unsigned int>(width * height));

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			Vector2f pixelPosition = canvasPosition + Vector2f(x, y);
			(*pixels)[x + y * static_cast<int>(width)].position = pixelPosition;
			(*pixels)[x + y * static_cast<int>(width)].color = Color::White;
		}
	}
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

vector<Vector2f> Canvas::getAllPointsOnLine(Vector2f pointA, Vector2f pointB) {
	vector<Vector2f> positions;

	float distance = sqrt(pow(pointB.x - pointA.x, 2) + pow(pointB.y - pointA.y, 2));
	int numberOfSteps = static_cast<int>(distance);

	float stepX = (pointB.x - pointA.x) / numberOfSteps;
	float stepY = (pointB.y - pointA.y) / numberOfSteps;

	for (int i = 0; i <= numberOfSteps; ++i) {
		float x = pointA.x + i * stepX;
		float y = pointA.y + i * stepY;
		positions.push_back(Vector2f(x, y));
	}

	return positions;
}

bool Canvas::isMouseOnCanvas(Vector2f mousePosition) const {
	return canvas.getGlobalBounds().contains(mousePosition);
}

bool Canvas::isPositionOnCanvas(Vector2f mousePosition) const {
	return contains({ mousePosition.x, mousePosition.y });
}

int Canvas::calculatePixelIndex(Vector2f mousePosition) const {
	Vector2i pixelPosition = Vector2i(mousePosition);
	size_t index;

	for (int x = 0; x < static_cast<int>(canvasSize.x); ++x) {
		for (int y = 0; y < static_cast<int>(canvasSize.y); ++y) {
			Vector2i currentPixelPosition = Vector2i(x, y) + Vector2i(canvasPosition);
			if (pixelPosition == currentPixelPosition) {
				index = (x + y * static_cast<int>(canvasSize.x));
				return static_cast<int>(index);
			}
		}
	}

	return -1;
}

Canvas::~Canvas() {
	delete pixels;
}

bool Canvas::contains(Vector2f point) const {
	return canvas.getGlobalBounds().contains(point);
}