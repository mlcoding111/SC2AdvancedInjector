#include "System.h"
#include "Image.h"
#include <iostream>

void System::printPos() {
    POINT p;
    while (1) {
        if (GetCursorPos(&p)) {
            std::cout << "x: " << p.x << "y:" << p.y << std::endl;
        }
    }
}

// Get pixel color at mouse position on { SPACE } press
void System::getMousePixel() {
    Image i;
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
                std::vector<int> rgb = i.getPixelColor(p.x, p.y);
                for (auto c : rgb) {
                    std::cout << c << "|";
                }
                std::cout << "\n";
            }


        }
        Sleep(10);
    }
}

void System::setPositions() {
    // Clear the vector
    this->i.xLocation.clear();
    this->i.yLocation.clear();

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
                this->i.xLocation.push_back(p.x);
                this->i.yLocation.push_back(p.y);
                Beep(750, 500);
                std::cout << "Location saved successfully" << std::endl;
                std::cout << "Current vector size : " << this->i.xLocation.size() << std::endl;
            }

        }
        Sleep(10);
    }

}