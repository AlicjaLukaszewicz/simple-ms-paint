#include "Paint.h"

Paint::Paint() : window(VideoMode(800, 600), "Paint Clone", Style::Close | Style::Titlebar) {
	interface = new Interface(window);
	window.setFramerateLimit(120);
	isMouseDown = false;
}

void Paint::run() {
	while (window.isOpen()) {
		processEvents(isMouseDown);
		render();
	}
}

void Paint::processEvents(bool& isMouseDown) {
	Event event;

	while (window.pollEvent(event)) {
		switch (event.type) {
		case Event::Closed:
			window.close();
			break;
		case Event::MouseMoved:
			handleMouseMoved(event, isMouseDown);
			break;

		case Event::MouseButtonPressed:
			handleMouseButtonPressed(event, isMouseDown);
			break;

		case Event::MouseButtonReleased:
			handleMouseButtonReleased(event, isMouseDown);
			break;
		default:
			break;
		}
	}
}

void Paint::handleMouseMoved(const Event& event, bool& isMouseDown) {
	Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));

	if (isMouseDown) {
		interface->onMouseHold(window, mousePosition);
	}
	else {
		interface->onMouseHover(window, mousePosition);
	}
}

void Paint::handleMouseButtonPressed(const Event& event, bool& isMouseDown) {
	if (event.mouseButton.button == Mouse::Left) {
		Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
		interface->onMouseClick(window, mousePosition);
		isMouseDown = true;
	}
}

void Paint::handleMouseButtonReleased(const Event& event, bool& isMouseDown) {
	if (event.mouseButton.button == Mouse::Left) {
		isMouseDown = false;
	}
}

void Paint::render() {
	window.clear(Color(255, 255, 255));
	interface->draw(window);
	window.display();
}