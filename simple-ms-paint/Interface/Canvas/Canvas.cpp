#include "Canvas.h"
#include "../../Utils/Tool/PencilTool/PencilTool.h"
#include "../../Utils/Tool/EraserTool/EraserTool.h"
#include "../../Utils/Tool/FillTool/FillTool.h"

const float PIXEL_SIZE = 5.0f;

Canvas::Canvas(float width, float height, Vector2f position, float padding)
	: canvasPosition(position.x + padding, position.y + padding),
	pixelSize(PIXEL_SIZE),
	pixels(nullptr) {
	canvasSize = { width - 2 * padding, height - 2 * padding };
	previousMousePosition = { 0, 0 };

	canvas.setSize(canvasSize);
	canvas.setPosition(canvasPosition);
	canvas.setFillColor(Color::White);

	initializePixels(width - 2 * padding, height - 2 * padding);
}

void Canvas::drawTo(RenderWindow& window) {
	window.draw(canvas);
	window.draw(*pixels);
}

void Canvas::onMouseHold(RenderWindow& window, vector<Button*> enabledButtons) {
	ColorButton* colorButton = findColorButton(enabledButtons);
	ToolButton* toolButton = findToolButton(enabledButtons);

	if (colorButton == nullptr || toolButton == nullptr) {
		return;
	}

	Color color = colorButton->getColor();

	if (toolButton->getType() == ToolButtonType::pencil) {
		PencilTool pencilTool;
		pencilTool.applyTool(*this, window, color);
	}
	else if (toolButton->getType() == ToolButtonType::eraser) {
		EraserTool eraserTool;
		eraserTool.applyTool(*this, window, canvas.getFillColor());
	}
}

void Canvas::onMouseClick(RenderWindow& window, vector<Button*> enabledButtons) {
	ColorButton* colorButton = findColorButton(enabledButtons);
	ToolButton* toolButton = findToolButton(enabledButtons);

	if (colorButton == nullptr || toolButton == nullptr) {
		return;
	}

	Color color = colorButton->getColor();

	if (toolButton->getType() == ToolButtonType::bucket) {
		FillTool fillTool;
		fillTool.applyTool(*this, window, color);
	}
}

void Canvas::initializePixels(float width, float height) {
	pixels = new VertexArray(Points, int(width * height));

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			Vector2f pixelPosition = canvasPosition + Vector2f(x, y);
			(*pixels)[x + y * width].position = pixelPosition;
			(*pixels)[x + y * width].color = Color::Transparent;
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

vector<Vector2f> Canvas::calculateHypotenusePositions(const Vector2f& pointA, const Vector2f& pointB, float stepSize) {
	vector<Vector2f> positions;

	float distance = sqrt((pointB.x - pointA.x) * (pointB.x - pointA.x) +
		(pointB.y - pointA.y) * (pointB.y - pointA.y));

	int numSteps = static_cast<int>(distance);

	float stepX = (pointB.x - pointA.x) / numSteps;
	float stepY = (pointB.y - pointA.y) / numSteps;

	for (int i = 0; i <= numSteps; ++i) {
		float x = pointA.x + i * stepX;
		float y = pointA.y + i * stepY;
		positions.push_back(Vector2f(x, y));
	}

	return positions;
}

bool Canvas::isMouseOnCanvas(Vector2f mousePosition) const {
	FloatRect canvasBounds = canvas.getGlobalBounds();
	return canvasBounds.contains(mousePosition);
}

bool Canvas::isModifiedPositionOnCanvas(Vector2f mousePosition, float i, float j) const {
	return contains({ mousePosition.x + i, mousePosition.y + j });
}

int Canvas::calculateIndex(Vector2f mousePosition, float i, float j) const {
	Vector2i pixelPosition = Vector2i(mousePosition);
	size_t index;

	for (int x = 0; x < canvasSize.x; ++x) {
		for (int y = 0; y < canvasSize.y; ++y) {
			Vector2i currentPixelPosition = Vector2i(x, y) + Vector2i(canvasPosition);
			if (pixelPosition == currentPixelPosition) {
				index = (x + y * canvasSize.x);
				return index;
			}
		}
	}
}

Canvas::~Canvas() {
	delete pixels;
}

bool Canvas::contains(Vector2f point) const
{
	return canvas.getGlobalBounds().contains(point);
}

Vector2i Canvas::getPreviousMousePosition() const
{
	return previousMousePosition;
}

VertexArray* Canvas::getPixels() const
{
	return pixels;
}

Vector2f Canvas::getPosition() const
{
	return canvasPosition;
}

Vector2f Canvas::getSize() const
{
	return canvasSize;
}

void Canvas::setPreviousMousePosition(Vector2i previousMousePosition)
{
	this->previousMousePosition = previousMousePosition;
}