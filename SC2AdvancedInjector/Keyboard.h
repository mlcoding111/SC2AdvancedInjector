#pragma once
/*
	0x34 = 4
	0x56 = V
*/
class Keyboard
{
private:
	int base;
	int queen;
public:
	void PressKey(int key);
	void SelectQueen();
	void SelectBase();
	void Inject();
};