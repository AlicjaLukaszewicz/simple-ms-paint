#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Button/Button.h"
#include "Sections/ToolSection/ToolSection.h"
#include "Sections/ColorSection/ColorSection.h"

class Menu {
private:
	RectangleShape menu;
	vector<MenuSection*> sections;

public:
	Menu(float width, float height, Color color);
	~Menu();

	void drawTo(RenderWindow& window);

	vector<Button*> getEnabledButtons() const;
	void setOtherButtonsToDisabled(vector<Button*> buttons, const Button* clickedButton);

	void onMouseHover(const Vector2f& mousePosition);
	void onMouseClick(const Vector2f& mousePosition);
	void handleButtonClick(const vector<Button*>& buttons, const Vector2f& mousePosition);
	void handleButtonHover(const vector<Button*>& buttons, const Vector2f& mousePosition);
};