#include "Interface.h"

const std::string IMAGES_PATH = "C:/Users/alicj/source/repos/simple-ms-paint/simple-ms-paint/Resources/";

Interface::Interface(sf::RenderWindow& window)
    : menuBar(window.getSize().x, 70, loadButtons(), sf::Color(245, 246, 247)),
    canvas(window.getSize().x, window.getSize().y - 70, sf::Vector2f(0, 70), 40) {
}

vector<Button> Interface::loadButtons()
{
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
    menuBar.drawTo(window);
    canvas.drawTo(window);
}

void Interface::onMouseHover(RenderWindow& window, Vector2f mousePosition) {
    menuBar.onMouseHover(mousePosition);
}

void Interface::onMouseClick(RenderWindow& window, Vector2f mousePosition) {
    menuBar.onMouseClick(mousePosition);
}