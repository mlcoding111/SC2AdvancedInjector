#pragma once

class Keyboard
{
private:
	int base;
	int queen;
	int larva;
public:
	Keyboard(int base = 0, int queen = 0, int larva = 0);
	void PressKey(int key);

	// All function related to keyboard
	void SelectQueen();
	void SelectBase();
	void SelectLarva();
};