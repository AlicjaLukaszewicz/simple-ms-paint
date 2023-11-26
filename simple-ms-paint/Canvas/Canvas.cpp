#include "Canvas.h"

Canvas::Canvas(float width, float height, Vector2f position, float padding) {
    canvas.setSize(Vector2f(width - 2 * padding, height - 2 * padding));
    canvas.setPosition(position.x + padding, position.y + padding);
    canvas.setFillColor(Color::White);

    pixels.setPrimitiveType(Points);
    pixels.resize(static_cast<size_t>(width * height));
}

void Canvas::drawTo(RenderWindow& window) {
    window.draw(canvas);
    window.draw(pixels);
}

void Canvas::onMouseHold(Vector2f mousePosition, Button enabledButton) {
    if (enabledButton.getFunction() == ButtonFunction::pencil) {
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (mousePosition.x >= canvas.getPosition().x &&
                mousePosition.y >= canvas.getPosition().y &&
                mousePosition.x <= canvas.getPosition().x + canvas.getSize().x &&
                mousePosition.y <= canvas.getPosition().y + canvas.getSize().y) {

                float pixelSize = 5.0f; // Adjust this size based on your preference
                std::size_t index = 0;

                // Draw additional points around the central position
                for (float i = -pixelSize / 2; i <= pixelSize / 2; ++i) {
                    for (float j = -pixelSize / 2; j <= pixelSize / 2; ++j) {
                        // Check if the new position is within the canvas boundaries
                        if (mousePosition.x + i >= canvas.getPosition().x &&
                            mousePosition.y + j >= canvas.getPosition().y &&
                            mousePosition.x + i <= canvas.getPosition().x + canvas.getSize().x &&
                            mousePosition.y + j <= canvas.getPosition().y + canvas.getSize().y) {

                            // Calculate the index in the VertexArray based on the modified mouse position
                            index = static_cast<std::size_t>((mousePosition.x + i - canvas.getPosition().x) +
                                (mousePosition.y + j - canvas.getPosition().y) * canvas.getSize().x);

                            // Update the color of the corresponding vertex in the VertexArray to black
                            pixels[index].position = mousePosition + Vector2f(i, j);
                            pixels[index].color = Color::Black;
                        }
                    }
                }
            }
        }
    }
}
