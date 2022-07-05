#pragma once

#include <Windows.h>
#include  <iostream>


/*
	0x34 = 4
	0x56 = V
*/
class Mouse
{
private:

public:
	Mouse();
	void RightClick();
	void LeftClick();
	void Move(int x, int y);
	void HoldleftClick();
	void ReleaseLeftClick();
	void MakeABox();
};

