#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class ButtonState
{
	enabled, disabled
};

class Button {
private:
	string name;
	RectangleShape button;
	RectangleShape buttonTexture;

	float width;
	float height;
	Vector2f position;

	Color color;
	ButtonState state;
	bool isHovered;

public:
	Button(string name, float width, float height, Texture* texture, ButtonState state);
	void setPosition(Vector2f position);
	void setState(ButtonState state);

	void setIsHovered(bool isHovered);
	bool getIsHovered() const;

	float getWidth();
	float getHeight();
	ButtonState getState();

	void drawTo(RenderWindow& window);
	bool isMouseOver(Vector2f mousePosition);
};