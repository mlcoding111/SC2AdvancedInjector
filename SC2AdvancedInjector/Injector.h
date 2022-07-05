#pragma once
#include <iostream>
#include "Mouse.h"
#include "Keyboard.h"
#include "windows.h"
#include "Image.h"
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
	Image i;

public:

	void MinimapInject();
	void LocationInject();

};

