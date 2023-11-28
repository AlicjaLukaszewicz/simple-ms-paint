#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Interface/Interface.h"

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(sf::VideoMode(800, 600), "Menu Example", Style::Close | Style::Titlebar);
    window.setFramerateLimit(120);

    Interface interface(window);
    bool isMouseDown = false;

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseMoved) {
                Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
                interface.onMouseHover(window, mousePosition);
            }
            
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
                interface.onMouseClick(window, mousePosition);
                isMouseDown = true;
            }

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                isMouseDown = false;
            }

            if (event.type == Event::MouseMoved && isMouseDown == true)
            {
                Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
                interface.onMouseHold(window, mousePosition);
            }
        }

        window.clear(Color(205, 215, 230));

        interface.draw(window);

        window.display();
    }

    return 0;
}
