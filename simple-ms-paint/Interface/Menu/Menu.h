#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Utils/Button/Button.h"
#include "Sections/ToolSection/ToolSection.h"
#include "Sections/ColorSection/ColorSection.h"

class Menu {
private:
	RectangleShape menu;
	vector<MenuSection*> sections;

public:
	Menu(float width, float height, Color color);
	~Menu();

	bool contains(Vector2f point) const;

	vector<Button*> getEnabledButtons() const;

	void drawTo(RenderWindow& window);

	void onMouseHover(const Vector2f& mousePosition);
	void onMouseClick(const Vector2f& mousePosition);
	bool isMouseWithinSectionBounds(const MenuSection* section, const Vector2f& mousePosition) const;
};