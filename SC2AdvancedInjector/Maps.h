#include <iostream>
#include <vector>
#include <string>
#include "Base.h"

#pragma once

class Maps
{
public:
	std::string Name;
	int basesCount;
	// Old list of bases for that map
	std::vector<std::tuple<short int, short int>> Bases;

	// Take in the name and list of bases
	Maps(std::string, int basesCount, std::vector<std::tuple<short int, short int>>);
};
