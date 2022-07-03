#pragma once

class Keyboard
{
private:
	int base;
	int queen;
	int larva;
public:
	Keyboard(int base, int queen, int larva);
	void PressKey(int key);

	// All function related to keyboard
	void SelectQueen();
	void SelectBase();
	void SelectLarva();
};