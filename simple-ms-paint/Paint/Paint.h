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

	void processEvents();
	void handleMouseMoved(const Event& event);
	void handleMouseButtonPressed(const Event& event);
	void handleMouseButtonReleased(const Event& event);

	void render();
};
