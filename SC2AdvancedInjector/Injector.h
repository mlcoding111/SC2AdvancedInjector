#pragma once
#include "Keyboard.h"
/*
	0x34 = 4
	0x56 = V
*/

class Injector
{
public:
	int base = 0x34;
	int inject = 0x56;
	Keyboard k;

public:

	void MinimapInject();
	void LocationInject();

};

