#pragma once

#include <SFML/Graphics.hpp>
#include "../../Utils/Button/ColorButton/ColorButton.h"
#include "../../Utils/Button/ToolButton/ToolButton.h"

class Canvas {
public:
	Canvas(float width, float height, Vector2f position, float padding);
	~Canvas();

	bool contains(Vector2f point) const;

	void drawTo(RenderWindow& window);
	void onMouseHold(RenderWindow& window, vector<Button*> enabledButtons);
	void onMouseClick(RenderWindow& window, vector<Button*> enabledButtons);

	Vector2i getPreviousMousePosition() const;
	VertexArray* getPixels() const;
	Vector2f getPosition() const;
	Vector2f getSize() const;
	Color getFillColor() const;

	void setPreviousMousePosition(Vector2i previousMousePosition);

	int calculatePixelIndex(Vector2f mousePosition) const;
	bool isPositionOnCanvas(Vector2f mousePosition) const;

	vector<Vector2f> getAllPointsOnLine(Vector2f pointA, Vector2f pointB);

	bool isMouseOnCanvas(Vector2f mousePosition) const;

private:
	RectangleShape canvas;
	Vector2f canvasSize;
	Vector2f canvasPosition;
	Vector2i previousMousePosition;
	VertexArray* pixels;

	ColorButton* findColorButton(const vector<Button*>& buttons) const;
	ToolButton* findToolButton(const vector<Button*>& buttons) const;

	void initializePixels(float width, float height);
};
