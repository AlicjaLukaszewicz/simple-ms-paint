#include "Paint.h"

Paint::Paint() : window(VideoMode(800, 600), "Paint Clone", Style::Close | Style::Titlebar) {
	interface = new Interface(window);
	window.setFramerateLimit(120);
	isMouseDown = false;
}

Paint::~Paint()
{
	delete interface;
}

void Paint::run() {
	while (window.isOpen()) {
		processEvents();
		render();
	}
}

void Paint::processEvents() {
	Event event;

	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed:
			window.close();
			break;
		case Event::MouseMoved:
			handleMouseMoved(event);
			break;

		case Event::MouseButtonPressed:
			handleMouseButtonPressed(event);
			break;

		case Event::MouseButtonReleased:
			handleMouseButtonReleased(event);
			break;
		default:
			break;
		}
	}
}

void Paint::handleMouseMoved(const Event& event) {
	if (isMouseDown) {
		interface->onMouseHold(window);
	}
	else {
		interface->onMouseHover(window);
	}
}

void Paint::handleMouseButtonPressed(const Event& event) {
	Vector2i mousePosition = Mouse::getPosition(window);
	if (event.mouseButton.button == Mouse::Left) {
		interface->onMouseClick(window);
		isMouseDown = true;
		interface->getCanvas()->setPreviousMousePosition(mousePosition);
	}
}

void Paint::handleMouseButtonReleased(const Event& event) {
	if (event.mouseButton.button == Mouse::Left) {
		isMouseDown = false;
	}
}

void Paint::render() {
	window.clear(Color(255, 255, 255));
	interface->draw(window);
	window.display();
}