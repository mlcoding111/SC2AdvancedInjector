#include "Maps.h"


Maps::Maps(std::string name, int basesCount, std::unordered_map <int, std::tuple<int, int>> locations)
{
    this->Name = name;
    this->Bases = locations;
    this->basesCount = basesCount;
}
