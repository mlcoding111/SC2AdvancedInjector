#pragma once
#include <iostream>
#include <Windows.h>
#include <iostream>
#include "Injector.h"
#include "Image.h"
#include "Base.h"
#include "Maps.h"


class System
{
public:
    Injector i;

    std::vector<Maps> maps;

    void printPos();
    void getMousePixel();
    void setPositions();
    void INIT();
    void START();
};