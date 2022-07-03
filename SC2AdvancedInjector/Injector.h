#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include <vector>
/*
	0x34 = 4
	0x56 = V
*/

class Injector
{
public:
	int base = 0x34;
	int inject = 0x56;
	std::vector<int> xLocation{ 275, 270, 276, 166, 43 };
	std::vector<int> yLocation{ 829, 934, 1040, 1039, 1050 };

	Keyboard k;
	Mouse m;

public:

	void MinimapInject();
	void LocationInject();

};

