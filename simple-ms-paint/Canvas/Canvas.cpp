#include "Canvas.h"

Canvas::Canvas(float width, float height, Vector2f position, float padding)
    : canvasPosition(position.x + padding, position.y + padding), pixelSize(5.0f)  {
    canvasSize = { width - 2 * padding, height - 2 * padding };

    canvas.setSize(canvasSize);
    canvas.setPosition(canvasPosition);
    canvas.setFillColor(Color::White);

    pixels.setPrimitiveType(Points);
    pixels.resize(static_cast<size_t>(width * height));
}

void Canvas::drawTo(RenderWindow& window) {
    window.draw(canvas);
    window.draw(pixels);
}

void Canvas::onMouseHold(Vector2f mousePosition, Button enabledButton) {
    if (isMouseOnCanvas(mousePosition)) {
        if (enabledButton.getFunction() == ButtonFunction::pencil) {
            handlePencilAction(mousePosition);
        }
        else if (enabledButton.getFunction() == ButtonFunction::eraser) {
            handleEraserAction(mousePosition);
        }
    }
}

void Canvas::handlePencilAction(Vector2f mousePosition) {
    updateCanvasPixels(mousePosition, Color::Black);
}

void Canvas::handleEraserAction(Vector2f mousePosition) {
    updateCanvasPixels(mousePosition, canvas.getFillColor());
}

void Canvas::updateCanvasPixels(Vector2f mousePosition, const Color& newColor) {
    std::size_t index = 0;

    for (float i = -pixelSize / 2; i <= pixelSize / 2; ++i) {
        for (float j = -pixelSize / 2; j <= pixelSize / 2; ++j) {
            if (isModifiedPositionOnCanvas(mousePosition, i, j)) {
                index = calculateIndex(mousePosition, i, j);

                pixels[index].position = mousePosition + Vector2f(i, j);
                pixels[index].color = newColor;
            }
        }
    }
}

bool Canvas::isMouseOnCanvas(Vector2f mousePosition) const {
    return (mousePosition.x >= canvas.getPosition().x &&
        mousePosition.y >= canvas.getPosition().y &&
        mousePosition.x <= canvas.getPosition().x + canvas.getSize().x &&
        mousePosition.y <= canvas.getPosition().y + canvas.getSize().y);
}

bool Canvas::isModifiedPositionOnCanvas(Vector2f mousePosition, float i, float j) const {
    return (mousePosition.x + i >= canvas.getPosition().x &&
        mousePosition.y + j >= canvas.getPosition().y &&
        mousePosition.x + i <= canvas.getPosition().x + canvas.getSize().x &&
        mousePosition.y + j <= canvas.getPosition().y + canvas.getSize().y);
}

size_t Canvas::calculateIndex(Vector2f mousePosition, float i, float j) const {
    return static_cast<size_t>((mousePosition.x + i - canvas.getPosition().x) +
        (mousePosition.y + j - canvas.getPosition().y) * canvas.getSize().x);
}
