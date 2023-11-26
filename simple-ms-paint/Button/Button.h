#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class ButtonState
{
	enabled, hovered, disabled
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

public:
	Button(string name, float width, float height, Texture* texture, ButtonState state);
	void setPosition(Vector2f position);
	void setState(ButtonState state);
	float getWidth();
	float getHeight();

	void drawTo(RenderWindow& window);
};