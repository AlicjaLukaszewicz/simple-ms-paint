#pragma once
#include <SFML/Graphics.hpp>
#include "../Button/Button.h"

using namespace sf;

class Canvas {
private:
	RectangleShape canvas;
	VertexArray pixels;

	Vector2f canvasSize;
	Vector2f canvasPosition;
	float pixelSize;

	bool isMouseOnCanvas(Vector2f mousePosition) const;
	void handlePencilAction(Vector2f mousePosition);
	void handleEraserAction(Vector2f mousePosition);
	void updateCanvasPixels(Vector2f mousePosition, const Color& newColor);
	size_t calculateIndex(Vector2f mousePosition, float i, float j) const;
	bool isModifiedPositionOnCanvas(Vector2f mousePosition, float i, float j) const;

public:
	Canvas(float width, float height, Vector2f position, float padding);

	void drawTo(RenderWindow& window);
	void onMouseHold(Vector2f mousePosition, Button enabledButton);
	void onMouseClick(Vector2f mousePosition, Button enabledButton);
};

