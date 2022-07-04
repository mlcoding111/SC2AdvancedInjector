#include "Injector.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "windows.h"
#include <iostream>

void Injector::MinimapInject() {
	// Select the queens
	this->k.SelectQueen();

	// Loop trough bases and move mouse
	for (std::size_t n = 0; n < min(xLocation.size(), yLocation.size()); n++)
	{
		auto  x = xLocation[n];
		auto& y = yLocation[n];
		this->m.Move(x, y);
		this->k.SelectLarva();
		this->m.LeftClick();

		// Display injects location
		std::cout << "Injecting at : { " << x << "," << y << " }" << std::endl;
	}
}

void Injector::LocationInject() {
	// Position center of screen
	int screenX = GetSystemMetrics(SM_CXSCREEN) / 2;
	int screenY = GetSystemMetrics(SM_CYSCREEN) / 2;

	// Loop trough bases and move mouse
	for (std::size_t n = 0; n < min(xLocation.size(), yLocation.size()); n++)
	{
		auto  x = xLocation[n];
		auto& y = yLocation[n];

		// Move to base
		this->m.Move(x, y);


		this->m.Move(screenX - 400, screenY + 250);
		Sleep(500);
		this->m.HoldleftClick();
		Sleep(500);
		this->m.Move(screenX + 400, screenY - 400);
		Sleep(500);
		this->m.ReleaseLeftClick();

		// Display injects location
		std::cout << "Injecting at : { " << x << "," << y << " }" << std::endl;
	}
}