// SC2AdvancedInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Injector.h"

void setPositions();
Injector i;

int main()
{
    // Sleep for 2 seconds then proceed to testing
    Sleep(2000);
    std::cout << "Sc2 advanced injector by Kenny" << std::endl;
    Mouse mouse;
    Keyboard keyboard;

    // i.MinimapInject();

    setPositions();
}

void setPositions() {
    std::cout << "Please Proceed. Press X when you're done .." << std::endl;
    while (1) {
        // 0x58 = x key
        if (GetAsyncKeyState(0x58))
        {
            printf("X Arrow key is Pressed");
            break;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            i.xLocation.clear();
            i.yLocation.clear();

            printf("Saving location");
            
        }
        Sleep(10);
    }

}