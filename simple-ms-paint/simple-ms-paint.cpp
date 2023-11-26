#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Interface/Interface.h"

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(sf::VideoMode(800, 600), "Menu Example", Style::Close | Style::Titlebar);

    Interface interface(window);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color(205, 215, 230));

        interface.draw(window);

        window.display();
    }

    return 0;
}