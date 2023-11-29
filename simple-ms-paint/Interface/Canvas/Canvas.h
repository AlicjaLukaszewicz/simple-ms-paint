#pragma once
#include <SFML/Graphics.hpp>
#include "../../Button/ColorButton/ColorButton.h"
#include "../../Button/ToolButton/ToolButton.h"

using namespace sf;

class Canvas {
private:
	RectangleShape canvas;
	Vector2f canvasSize;
	Vector2f canvasPosition;

	float pixelSize;
	VertexArray* pixels;

	size_t calculateIndex(Vector2f mousePosition, float i, float j) const;

	void handlePencilAction(Vector2f mousePosition, const Color& color);
	void handleEraserAction(Vector2f mousePosition);
	void updateCanvasPixels(Vector2f mousePosition, const Color& newColor);

	bool isMouseOnCanvas(Vector2f mousePosition) const;
	bool isModifiedPositionOnCanvas(Vector2f mousePosition, float i, float j) const;

	void initializePixels(float width, float height);
	ColorButton* findColorButton(const std::vector<Button*>& buttons) const;
	ToolButton* findToolButton(const std::vector<Button*>& buttons) const;

public:
	Canvas(float width, float height, Vector2f position, float padding);
	~Canvas();

	void drawTo(RenderWindow& window);
	void onMouseHold(Vector2f mousePosition, vector<Button*> enabledButtons);
	//void onMouseClick(Vector2f mousePosition, vector<Button*> enabledButtons);
};
