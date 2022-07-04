#include "Windows.h"
#include "Keyboard.h"
#include <iostream>
/*
    0x34 = 4
    0x56 = V
    0x33 = 3
*/

Keyboard::Keyboard(int base, int queen, int larva)
    : base{ 0x33 }, queen{ 0x34 }, larva{ 0x56 }{
    std::cout << "Keyboard success." << std::endl;
}


void Keyboard::PressKey(int key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

    SendInput(1, &input, sizeof(INPUT));
}

void Keyboard::SelectQueen() {
    this->PressKey(this->queen);
}

void Keyboard::SelectBase() {
    this->PressKey(this->base);
}

void Keyboard::SelectLarva() {
    this->PressKey(this->larva);
}