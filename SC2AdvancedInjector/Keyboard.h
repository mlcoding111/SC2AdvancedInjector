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
	Keyboard(int base = 0x34, int queen = 0x56);

	void SelectQueen();
	void SelectBase();
	void Inject();


	~Keyboard();
};