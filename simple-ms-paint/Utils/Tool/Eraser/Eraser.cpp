#include "Eraser.h"

const int SIZE = 2;

void Eraser::erase(Canvas& canvas, RenderWindow& window)
{
	Vector2f currMousePosition = Vector2f(Mouse::getPosition(window));
	Vector2f prevMousePosition = Vector2f(canvas.getPreviousMousePosition());

	vector<Vector2f> positions =
		canvas.getAllPointsOnLine(currMousePosition, prevMousePosition);

	VertexArray* pixels = canvas.getPixels();

	int index;

	for (int i = -SIZE; i <= SIZE; ++i) {
		for (int j = -SIZE; j <= SIZE; ++j) {
			Vector2f position = currMousePosition + Vector2f(i, j);

			// Check if the modified position is on the canvas
			if (canvas.isPositionOnCanvas(position)) {
				int index = canvas.calculatePixelIndex(position);
				(*pixels)[index].position = position;
				(*pixels)[index].color = canvas.getFillColor();
			}
		}
	}

	canvas.setPreviousMousePosition(Vector2i(currMousePosition));
}