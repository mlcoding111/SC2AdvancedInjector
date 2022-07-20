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
Injector i;
Image im;
Mouse mouse;
Keyboard keyboard;
System sys;

int main()
{
    Maps maps[7];
    Sleep(2000);
    std::cout << "SC2Advanced Injector by Kenny" << std::endl;    
    std::unordered_map <int, std::tuple<int, int>> mymap;
    mymap[1] = { 3,2 };
    mymap[2] = { 3,2 };
    mymap[3] = { 3,2 };



        
    sys.START();
}