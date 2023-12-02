#pragma once
#include <SFML/Graphics.hpp>

#include "../Tool.h"

class FillTool : public Tool {
private:
	vector<Vector2f> filledPositions;

	void fillConnectedRegion(Canvas& canvas, VertexArray* pixels, const Color& startColor, const Color& fillColor, size_t currentIndex);

public:
	FillTool();
	void applyTool(Canvas& canvas, RenderWindow& window, const Color& color);
};
