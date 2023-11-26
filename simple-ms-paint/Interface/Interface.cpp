#include "Interface.h"

const string IMAGES_PATH = "C:/Users/alicj/source/repos/simple-ms-paint/simple-ms-paint/Resources/";

Interface::Interface(RenderWindow& window) {
    const float menuBarHeight = 70;
    const float windowWidth = window.getSize().x;
    const float windowHeight = window.getSize().y;

    buttons = loadButtons();

    createMenuBar(windowWidth, menuBarHeight, buttons, Color(245, 246, 247));
}

vector<Button> Interface::loadButtons() {
    const float buttonSize = 50;
    vector<Button> buttons;

    buttons.emplace_back("Pencil", buttonSize, buttonSize, loadTexture("pencil.png"), ButtonState::enabled);
    buttons.emplace_back("Bucket", buttonSize, buttonSize, loadTexture("paint-bucket.png"), ButtonState::disabled);
    buttons.emplace_back("Eraser", buttonSize, buttonSize, loadTexture("eraser.png"), ButtonState::disabled);
    buttons.emplace_back("ColorPicker", buttonSize, buttonSize, loadTexture("pipette.png"), ButtonState::disabled);

    return buttons;
}

Texture* Interface::loadTexture(const string& filename) {
    Texture* texture = new Texture();
    if (!texture->loadFromFile(IMAGES_PATH + filename)) {
        cerr << "Failed to load texture: " << filename << endl;
    }

    return texture;
}

void Interface::draw(RenderWindow& window) {
    window.draw(menuBar);

    for (auto& button : buttons) {
        button.drawTo(window);
    }

    window.draw(canvas);
}

void Interface::createMenuBar(float width, float height, vector<Button> buttons, Color color) {
    menuBar.setSize(Vector2f(width, height));
    menuBar.setPosition(0, 0);
    menuBar.setFillColor(color);

    const float totalButtonWidth = static_cast<float>(buttons.size()) * buttons[0].getWidth();
    const float horizontalSpacing = (width - totalButtonWidth) / (buttons.size() + 1);

    Vector2f buttonPosition(horizontalSpacing, (height - buttons[0].getHeight()) / 2.0f);

    for (auto& button : buttons) {
        button.setPosition(buttonPosition);
        buttonPosition.x += button.getWidth() + horizontalSpacing;
    }

    this->buttons = buttons;
}

void Interface::createCanvas(float width, float height, Vector2f position) {
    canvas.setSize(Vector2f(width, height));
    canvas.setPosition(position);
}

void Interface::onMouseHover(RenderWindow& window, Vector2f mousePosition) {
    for (auto& button : buttons) {
        if (button.isMouseOver(mousePosition)) {
            button.setIsHovered(true);
        }
        else
        {
            button.setIsHovered(false);
        }
    }
}

void Interface::onMouseClick(RenderWindow& window, Vector2f mousePosition) {
    for (auto& button : buttons) {
        if (button.isMouseOver(mousePosition)) {
            if (button.getState() == ButtonState::disabled) {
                button.setState(ButtonState::enabled);
                for (auto& otherButton : buttons) {
                    if (&otherButton != &button) {
                        otherButton.setState(ButtonState::disabled);
                    }
                }
            }
        }
    }
}


