#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Button/Button.h"
#include "Sections/ToolSection/ToolSection.h"

class MenuBar {
private:
	RectangleShape menuBar;
	ToolSection toolsSection;
	vector<MenuSection> sections;

public:
	MenuBar(float width, float height, Color color);

	void drawTo(RenderWindow& window);
	bool onMouseHover(const Vector2f& mousePosition);
	bool onMouseClick(const Vector2f& mousePosition);
	vector<Button*> getEnabledButtons();
	void setOtherButtonsToDisabled(vector<Button*> buttons, const Button* clickedButton);
};