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
	std::unordered_map <int, std::tuple<int, int>> Bases;

	// Take in the name and list of bases
	Maps(std::string, int basesCount, std::unordered_map <int, std::tuple<int, int>>);
};
