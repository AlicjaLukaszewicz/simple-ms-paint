#pragma once

#include <SFML/Graphics.hpp>
#include "../Interface/Interface.h"

using namespace sf;

class Paint {
private:
	RenderWindow window;
	Interface* interface;
	bool isMouseDown;

public:
	Paint();
	~Paint();

	void run();

	void processEvents(bool& isMouseDown);
	void handleMouseMoved(const Event& event, bool& isMouseDown);
	void handleMouseButtonPressed(const Event& event, bool& isMouseDown);
	void handleMouseButtonReleased(const Event& event, bool& isMouseDown);

	void render();
};
