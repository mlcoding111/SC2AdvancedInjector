// SC2AdvancedInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Keyboard.h"
#include "Mouse.h"

// Map bases location
int x[] = { 275, 270, 276, 166, 43 };
int y[] = { 829, 934, 1040, 1039, 1050 };

// Store the amount of bases to loop trough
int size = sizeof(x) / sizeof(x[0]);

int main()
{
    // Sleep for 2 seconds then proceed to testing
    Sleep(2000);
    std::cout << "Sc2 advanced injector by Kenny" << std::endl;
    Mouse mouse;
    Keyboard keyboard;
}