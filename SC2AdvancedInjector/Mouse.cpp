#include "Mouse.h"



Mouse::Mouse() {
    std::cout << "Mouse success." << std::endl;
}

void Mouse::LeftClick() {
    INPUT input;

    ZeroMemory(&input, sizeof(input));

    input.mi.time = 0;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, &input, sizeof(INPUT));

    Sleep(10);
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::HoldleftClick() {
    INPUT input;
    ZeroMemory(&input, sizeof(input));

    input.mi.time = 0;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::ReleaseLeftClick() {
    INPUT input;
    ZeroMemory(&input, sizeof(input));

    input.mi.time = 0;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::RightClick() {
    INPUT input;
    ZeroMemory(&input, sizeof(input));

    input.mi.time = 0;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN);
    SendInput(1, &input, sizeof(INPUT));

    Sleep(10);
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP);
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::Move(int x, int y) {
    
    // Get screen W and H
    double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;

    // Convert to absolute position
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);

    // Send Input
    INPUT input;
    ZeroMemory(&input, sizeof(input));

    input.mi.time = 0;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dx = fx;
    input.mi.dy = fy;

    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::MakeABox() {
    // Position center of screen
    int screenX = GetSystemMetrics(SM_CXSCREEN) / 2;
    int screenY = GetSystemMetrics(SM_CYSCREEN) / 2;

    // Make a box to select queen close to hatchery
    this->Move(screenX - 400, screenY + 250);
    Sleep(10);
    this->HoldleftClick();
    Sleep(10);
    this->Move(screenX + 400, screenY - 400);
    Sleep(10);
    this->ReleaseLeftClick();
    this->Move(screenX, screenY);
}