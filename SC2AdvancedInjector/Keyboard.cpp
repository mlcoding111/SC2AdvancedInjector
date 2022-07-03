#include "Windows.h"
#include "Keyboard.h"

void Keyboard::PressKey() {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = 0x56;
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

    SendInput(1, &input, sizeof(INPUT));
}