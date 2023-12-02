#include "PencilTool.h"

PencilTool::PencilTool()
{
}

void PencilTool::applyTool(Canvas& canvas, RenderWindow& window, const Color& color) {
	Vector2f currMousePosition = Vector2f(Mouse::getPosition(window));
	Vector2f prevMousePosition = Vector2f(canvas.getPreviousMousePosition());

	vector<Vector2f> allPositions =
		canvas.calculateHypotenusePositions(currMousePosition, prevMousePosition, 1);

	int index;
	VertexArray* pixels = canvas.getPixels();

	for (const auto& position : allPositions) {
		if (canvas.isModifiedPositionOnCanvas(position, 0, 0)) {
			index = canvas.calculateIndex(position, 0, 0);
			(*pixels)[index].position = position;
			(*pixels)[index].color = color;
		}
	}
	canvas.setPreviousMousePosition(Vector2i(currMousePosition));
}