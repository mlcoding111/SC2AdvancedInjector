#include "Injector.h"

void Injector::MinimapInject() {

	// Select the queens
	this->k.SelectQueen();

	// Check if base still active
	std::vector<int> rgb = this->i.getPixelColor(300, 300);
	for (auto c : rgb) {
		std::cout << c << std::endl;
	}

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


	// Loop trough bases and move mouse
	for (std::size_t n = 0; n < min(xLocation.size(), yLocation.size()); n++)
	{
		auto  x = xLocation[n];
		auto& y = yLocation[n];

		// Move camera to base
		this->m.Move(x, y);
		this->m.LeftClick();

		this->m.MakeABox();

		// Proceed to inject
		this->k.SelectLarva();
		this->m.LeftClick();	


		// Display injects location
		std::cout << "Injecting at : { " << x << "," << y << " }" << std::endl;
	}

}