// SC2AdvancedInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://github.com/nlohmann/json

#include <iostream>
#include <Windows.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Injector.h"
#include "Image.h"
#include "System.h"


// Functions header
void START();

// Global Variables
Injector i;
Image im;
Mouse mouse;
Keyboard keyboard;
System sys;

int main()
{
    Sleep(2000);

    std::cout << "SC2Advanced Injector by Kenny" << std::endl;
    START();
}

// Start main process and listen for key press
void START() {
    sys.setPositions(); // Ask the position then start program
    std::cout << "Press Q to exit at any time." << std::endl;
    while (1) {
        if (GetAsyncKeyState(0x51)) // Exit if Q pressed
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE)) // Inject if SPACE pressed
        {
            // i.LocationInject();
            i.MinimapInject();
        }
        Sleep(10);
    }
}
