#include "Maps.h"


Maps::Maps(std::string name, int basesCount, std::vector<std::tuple<short int, short int>> locations)
{
    this->Name = name;
    this->Bases = locations;
    this->basesCount = basesCount;
}
