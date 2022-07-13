// SC2AdvancedInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://github.com/nlohmann/json

#include <iostream>
#include <Windows.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Injector.h"
#include "Image.h"


// Functions header
void setPositions();
void START();
void printPos();
void getMousePixel();

// Global Variables
Injector i;
Image im;
Mouse mouse;
Keyboard keyboard;

int main()
{
    Sleep(2000);

    std::cout << "SC2Advanced Injector by Kenny" << std::endl;
    START();
   
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

// Get pixel color at mouse position on { SPACE } press
void getMousePixel() {
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
}

// Start main process and listen for key press
void START() {
    setPositions(); // Ask the position then start program
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
        // 0x50 = p key
        if (GetAsyncKeyState(0x50))
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