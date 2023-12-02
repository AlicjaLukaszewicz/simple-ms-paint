#pragma once
#include "../Tool.h"
class EraserTool : public Tool {
public:
	EraserTool();
	void applyTool(Canvas& canvas, RenderWindow& window, const Color& color) override;
};
