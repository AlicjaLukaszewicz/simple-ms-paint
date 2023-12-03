#pragma once
#include "../../../Interface/Canvas/Canvas.h"
#include "../../../Observer/Observer.h"

class ColorPicker : public Observable {
public:
	static ColorPicker& getInstance();
	static void pick(Canvas& canvas, RenderWindow& window);
};
