#include "Injector.h"

void Injector::MinimapInject() {
	// Select the queens
	this->k.SelectQueen();

	// Light Green 0|140|0
	// Strong Green 0|255|0

	// Loop trough bases and move mouse
	for (std::size_t n = 0; n < min(xLocation.size(), yLocation.size()); n++)
	{
		auto  x = xLocation[n];
		auto& y = yLocation[n];

		// Check if base still active
		std::vector<int> rgb = this->i.getPixelColor(x, y);

		// Check if the base location is matching base color
		if (rgb == i.LightGreenRgb || rgb == i.StrongGreenRgb) {
			std::cout << "Base Detected At : {" << x << "." << y << "}" << std::endl;

			this->m.Move(x, y);
			this->k.SelectLarva();
			this->m.LeftClick();

			// Display injects location
			std::cout << "Injecting at : { " << x << "," << y << " }" << std::endl;
		}
		else {
			// If no base detected..
			std::cout << "Not base detected at : { " << x << "," << y << " }" << std::endl;
		}

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