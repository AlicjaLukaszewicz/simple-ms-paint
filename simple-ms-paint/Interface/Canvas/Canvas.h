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

	void setPreviousMousePosition(Vector2i previousMousePosition);

	int calculateIndex(Vector2f mousePosition, float i, float j) const;
	bool isModifiedPositionOnCanvas(Vector2f mousePosition, float i, float j) const;
	vector<Vector2f> calculateHypotenusePositions(
		const Vector2f& pointA, const Vector2f& pointB, float stepSize);

	bool isMouseOnCanvas(Vector2f mousePosition) const;

private:
	RectangleShape canvas;
	Vector2f canvasSize;
	Vector2f canvasPosition;
	Vector2i previousMousePosition;
	float pixelSize;
	VertexArray* pixels;

	ColorButton* findColorButton(const vector<Button*>& buttons) const;
	ToolButton* findToolButton(const vector<Button*>& buttons) const;

	void initializePixels(float width, float height);
};
