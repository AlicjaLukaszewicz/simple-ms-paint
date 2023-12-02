#pragma once
#include "../Tool.h"
class PencilTool : public Tool {
public:
	PencilTool();
	void applyTool(Canvas& canvas, RenderWindow& window, const Color& color) override;
};
