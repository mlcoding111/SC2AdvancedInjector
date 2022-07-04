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

    while (1) {
        std::cout << "Press Q to exit at any time." << std::endl;
        // 0x51 = q key
        if (GetAsyncKeyState(0x51))
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            i.MinimapInject();
        }
        Sleep(10);
    }

}

void setPositions() {
    i.xLocation.clear();
    i.yLocation.clear();
    bool settingPost = true;
    std::cout << "Please Proceed. Press X when you're done .." << std::endl;
    while (settingPost) {
        // 0x58 = x key
        if (GetAsyncKeyState(0x58))
        {
            settingPost = false;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {

            POINT p;

            if (GetCursorPos(&p)) {
                i.xLocation.push_back(p.x);
                i.yLocation.push_back(p.y);
                Beep(750, 500);
                std::cout << "Location saved successfully" << std::endl;
                std::cout << "Current vector size : " << i.xLocation.size() << std::endl;
            }
            
        }
        Sleep(10);
    }

}