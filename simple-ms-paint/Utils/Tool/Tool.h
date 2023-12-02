#pragma once
#include <SFML/Graphics.hpp>
#include "../../Interface/Canvas/Canvas.h"

using namespace sf;
using namespace std;

class Tool {
public:
	virtual ~Tool() = default;

	virtual void applyTool(Canvas& canvas, RenderWindow& window, const Color& color) = 0;
};
