#pragma once
#include "../../../Interface/Canvas/Canvas.h"

class Fill {
private:
	static void fillConnectedRegion(Canvas& canvas, Color& colorOfClickedPixel, Color& fillColor, int indexOfClickedPixel);

public:
	static void fill(Canvas& canvas, RenderWindow& window, Color& color);
};
