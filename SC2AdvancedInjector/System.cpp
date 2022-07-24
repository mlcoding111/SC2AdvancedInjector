#include "System.h"


// Simply return current mouse position
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

// Ask for input to set mousue position
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
                std::cout << "Location saved successfully at : { " << p.x << "." << p.y << " }" << std::endl;
                std::cout << "Current vector size : " << this->i.xLocation.size() << std::endl;
            }

        }
        Sleep(10);
    }

}

// Function that run to initiate the bot
void System::START() {
    this->setPositions(); // Ask the position then start program
    std::cout << "Press Q to exit at any time." << std::endl;
    while (1) {
        if (GetAsyncKeyState(0x51)) // Exit if Q pressed
        {
            break;
        }
        if (GetAsyncKeyState(VK_SPACE)) // Inject if SPACE pressed
        {
            // i.LocationInject();
            this->i.MinimapInject();
        }
        Sleep(10);
    }
}

void System::INIT() {
    // Vector which contain a vector of all bases location
    std::vector<std::tuple<short int, short int>> Waterfalll{ 
        {239, 838}, 
        {196,831},
        {206,894}, 
        {136,827},
        {242,928}, 
        {212,962},
        {234,1010}, 
        {182,1041},
        {85,857}, 
        {106,907},
        {75,940}, 
        {111,976},
        {123,1038}, 
        {78,1031} 
    };
    // Will need to create a new base for each location then pass it into map
    Maps p("Waterfall", Waterfalll.size(), Waterfalll);
    this->maps.push_back(p);

    // Iterate trough all bases positions of the maps
    for (auto& tuple : Waterfalll) {
        std::cout << std::get<0>(tuple) << " " << std::get<1>(tuple) << std::endl;
    }
 }