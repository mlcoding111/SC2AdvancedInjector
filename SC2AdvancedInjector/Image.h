#pragma once
#include "Windows.h"
#include <vector>

class Image
{
private:

public:
	std::vector<int> getPixelColor(int x, int y);
};

