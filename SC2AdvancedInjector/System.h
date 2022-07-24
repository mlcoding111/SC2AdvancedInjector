#pragma once
#include <iostream>
#include <Windows.h>
#include <iostream>
#include "Injector.h"
#include "Image.h"
#include "Base.h"


class System
{
public:
    Injector i;

    const int MAPS_COUNT = 7;

    void printPos();
    void getMousePixel();
    void setPositions();
    void INIT();
    void START();
};