#include "ColorPicker.h"

ColorPicker& ColorPicker::getInstance()
{
	static ColorPicker instance;
	return instance;
}

void ColorPicker::pick(Canvas& canvas, RenderWindow& window)
{
	Vector2f clickedPixelPosition = Vector2f(Mouse::getPosition(window));
	int indexOfClickedPixel = canvas.calculatePixelIndex(clickedPixelPosition);
	VertexArray* pixels = canvas.getPixels();

	Color colorOfClickedPixel = (*pixels)[indexOfClickedPixel].color;

	ColorPicker::getInstance().notifyObservers(colorOfClickedPixel);
}