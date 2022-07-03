#include "Windows.h"
#include "Keyboard.h"

void Keyboard::PressKey(int key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

    SendInput(1, &input, sizeof(INPUT));
}