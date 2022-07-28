// SC2AdvancedInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://github.com/nlohmann/json

#include <iostream>
#include <Windows.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Injector.h"
#include "Image.h"
#include "System.h"
#include <fstream>
#include <unordered_map> 
#include "Maps.h"

using namespace std;


// Global Variables
/*
* Used for debugging and future testing
Injector i;
Image im;
Mouse mouse;
Keyboard keyboard;
*/

System sys;

int main()
{
    Sleep(2000);
    std::cout << "SC2Advanced Injector by Kenny" << std::endl;    
    // sys.setPositions();
    sys.INIT();
    std::cout << sys.maps[0].Name << std::endl;
    // sys.START();
}