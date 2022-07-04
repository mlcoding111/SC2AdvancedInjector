#include "Injector.h"
#include "Mouse.h"
#include "Keyboard.h"
#include <iostream>

void Injector::MinimapInject() {
	// Select the queens
	this->k.SelectQueen();

	// Loop trough bases and move mouse
	for (std::size_t n = 0; n < std::min(xLocation.size(), yLocation.size()); n++)
	{
		auto  x = xLocation[n];
		auto& y = yLocation[n];
		this->m.MoveMouse(x, y);
		this->k.SelectLarva();
		this->m.LeftClick();

		// Display injects location
		std::cout << "Injecting at : { " << x << "," << y << " }" << std::endl;
	}
}

void Injector::LocationInject() {

}