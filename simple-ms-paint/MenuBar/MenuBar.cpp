// MenuBar.cpp
#include "MenuBar.h"

MenuBar::MenuBar(float width, float height, vector<Button> buttons, sf::Color color)
    : buttons(buttons) {
    menuBar.setSize(sf::Vector2f(width, height));
    menuBar.setPosition(0, 0);
    menuBar.setFillColor(color);

    const float totalButtonWidth = static_cast<float>(buttons.size()) * buttons[0].getWidth();
    const float horizontalSpacing = (width - totalButtonWidth) / (buttons.size() + 1);

    sf::Vector2f buttonPosition(horizontalSpacing, (height - buttons[0].getHeight()) / 2.0f);

    for (auto& button : this->buttons) {
        button.setPosition(buttonPosition);
        buttonPosition.x += button.getWidth() + horizontalSpacing;
    }
}

void MenuBar::drawTo(sf::RenderWindow& window) {
    window.draw(menuBar);

    for (auto& button : buttons) {
        button.drawTo(window);
    }
}

bool MenuBar::onMouseHover(const sf::Vector2f& mousePosition) {
    bool anyButtonHovered = false;

    for (auto& button : buttons) {
        if (button.isMouseOver(mousePosition)) {
            button.setIsHovered(true);
            anyButtonHovered = true;
        }
        else {
            button.setIsHovered(false);
        }
    }

    return anyButtonHovered;
}

bool MenuBar::onMouseClick(const sf::Vector2f& mousePosition) {
    bool anyButtonClicked = false;

    for (auto& button : buttons) {
        if (button.isMouseOver(mousePosition)) {
            if (button.getState() == ButtonState::disabled) {
                button.setState(ButtonState::enabled);
                for (auto& otherButton : buttons) {
                    if (&otherButton != &button) {
                        otherButton.setState(ButtonState::disabled);
                    }
                }
                anyButtonClicked = true;
            }
        }
    }

    return anyButtonClicked;
}