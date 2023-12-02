#include "FillTool.h"
#include <stack>

FillTool::FillTool()
{
}

void FillTool::applyTool(Canvas& canvas, RenderWindow& window, const Color& color) {
	Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));

	VertexArray* pixels = canvas.getPixels();
	size_t pixelsCount = pixels->getVertexCount();

	size_t currentIndex = canvas.calculateIndex(mousePosition, 0, 0);
	Color startColor = (*pixels)[currentIndex].color;

	fillConnectedRegion(canvas, pixels, startColor, color, currentIndex);
}

void FillTool::fillConnectedRegion(Canvas& canvas, VertexArray* pixels, const Color& startColor, const Color& fillColor, size_t currentIndex) {
	stack<size_t> stack;
	stack.push(currentIndex);

	while (!stack.empty()) {
		size_t current = stack.top();
		stack.pop();

		if (current >= 0 && current < pixels->getVertexCount()
			&& (*pixels)[current].color == startColor) {
			(*pixels)[current].color = fillColor;

			stack.push(current - 1);
			stack.push(current + 1);
			stack.push(current - canvas.getSize().x);
			stack.push(current + canvas.getSize().x);
		}
	}
}