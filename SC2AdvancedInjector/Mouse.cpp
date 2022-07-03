#include "Mouse.h"
#include <Windows.h>
#include  <iostream>


Mouse::Mouse() {
    std::cout << "Mouse success." << std::endl;
}

void Mouse::LeftClick() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, &input, sizeof(INPUT));

    Sleep(10);
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::RightClick() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN);
    SendInput(1, &input, sizeof(INPUT));

    Sleep(10);
    input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP);
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::MoveMouse(int x, int y) {
    
    // Get screen W and H
    double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;

    // Convert to absolute position
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);

    // Send Input
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dx = fx;
    input.mi.dy = fy;

    SendInput(1, &input, sizeof(INPUT));
}