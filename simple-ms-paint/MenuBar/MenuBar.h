#include <SFML/Graphics.hpp>
#include <vector>
#include "../Button/Button.h"

class MenuBar {
private:
    vector<Button> buttons;
    RectangleShape menuBar;

public:
    MenuBar(float width, float height, vector<Button> buttons, Color color);

    void drawTo(sf::RenderWindow& window);
    bool onMouseHover(const sf::Vector2f& mousePosition);
    bool onMouseClick(const sf::Vector2f& mousePosition);
};