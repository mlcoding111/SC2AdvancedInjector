#pragma once
#include "Windows.h"
#include <vector>

class Image
{
private:

public:
	std::vector<int> LightGreenRgb{ 0, 140, 0 };
	std::vector<int> StrongGreenRgb{ 0, 255, 0 };

	std::vector<int> getPixelColor(int x, int y);
};

