// SC2AdvancedInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://github.com/nlohmann/json

#include <iostream>
#include <Windows.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Injector.h"
#include "Image.h"

void setPositions();
void START();
void printPos();
void getPixel();
Injector i;

int main()
{
    // Sleep for 2 seconds then proceed to testing
    Sleep(2000);
    std::cout << "Sc2 advanced injector by Kenny" << std::endl;
    Mouse mouse;
    Keyboard keyboard;
    Image im;

    while (1) {
        POINT p;
        // 0x51 = q key
        if (GetAsyncKeyState(0x51))
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {

            if (GetCursorPos(&p)) {
                std::vector<int> rgb = im.getPixelColor(p.x, p.y);
                for (auto c : rgb) {
                    std::cout << c << "|";
                }
                std::cout << "\n";
            }


        }
        Sleep(10);
    }
    
    // setPositions(); // Ask the position then start program
    // START(); // Listen for keypress to inject. This is the main loop
}

void printPos() {
    POINT p;
    while (1) {
        if (GetCursorPos(&p)) {
            std::cout << "x: " << p.x << "y:" << p.y << std::endl;
        }
    }
}

void START() {

    std::cout << "Press Q to exit at any time." << std::endl;
    while (1) {
        // 0x51 = q key
        if (GetAsyncKeyState(0x51))
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            // i.LocationInject();
            i.MinimapInject();
        }
        Sleep(10);
    }
}

void setPositions() {
    // Clear the vector
    i.xLocation.clear();
    i.yLocation.clear();

    std::cout << "Please Proceed. Press {x} when you're done .." << std::endl;
    while (1) {
        // 0x58 = x key
        if (GetAsyncKeyState(0x58))
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {

            POINT p;

            if (GetCursorPos(&p)) {
                // Set new location to current mouse position
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