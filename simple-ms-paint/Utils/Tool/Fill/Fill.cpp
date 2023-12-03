#include <stack>
#include "Fill.h"

void Fill::fillConnectedRegion(Canvas& canvas, Color& colorOfClickedPixel, Color& fillColor, int indexOfClickedPixel)
{
	stack<int> stack;
	stack.push(indexOfClickedPixel);
	VertexArray* pixels = canvas.getPixels();

	while (!stack.empty()) {
		int current = stack.top();
		stack.pop();

		if (current >= 0 && current < pixels->getVertexCount()
			&& (*pixels)[current].color == colorOfClickedPixel) {
			(*pixels)[current].color = fillColor;

			stack.push(current - 1);
			stack.push(current + 1);
			stack.push(current - canvas.getSize().x);
			stack.push(current + canvas.getSize().x);
		}
	}
}

void Fill::fill(Canvas& canvas, RenderWindow& window, Color& fillColor) {
	Vector2f clickedPixelPosition = Vector2f(Mouse::getPosition(window));
	int indexOfClickedPixel = canvas.calculatePixelIndex(clickedPixelPosition);

	VertexArray* pixels = canvas.getPixels();
	Color colorOfClickedPixel = (*pixels)[indexOfClickedPixel].color;
	fillConnectedRegion(canvas, colorOfClickedPixel, fillColor, indexOfClickedPixel);
}