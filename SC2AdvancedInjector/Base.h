// This class will contain information about each base on the current map
// When map load, software will fetch map data to the api
#include <vector>
#include <iostream>

#pragma once
class Base
{
private:
	int id;
public:
	bool IS_UP = false;
	bool IS_BUILDING = false;
	std::vector<int> xLocation = {};
	std::vector<int> yLocation = {};
};

