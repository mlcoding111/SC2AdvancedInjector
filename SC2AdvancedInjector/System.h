#pragma once
#include <iostream>
#include <Windows.h>
#include "Injector.h"

class System
{
public:
    Injector i;

    void printPos();
    void getMousePixel();
    void setPositions();
};