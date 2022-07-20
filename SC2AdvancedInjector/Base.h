// This class will contain information about each base on the current map
// When map load, software will fetch map data to the api
#include <vector>
#include <unordered_map> 
#include <iostream>

#pragma once
class Base
{
private:

public:
	int id;
	bool IS_UP = false;
	bool IS_BUILDING = false;
	// Hold up the locations
	std::tuple<short int, short int> Location;

	Base(std::tuple<short int, short int>);
};

