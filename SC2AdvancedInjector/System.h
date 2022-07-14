#pragma once
#include <iostream>
#include <Windows.h>
#include <iostream>
#include "Injector.h"

class System
{
public:
    Injector i;

    void printPos();
    void getMousePixel();
    void setPositions();
    void START();
};