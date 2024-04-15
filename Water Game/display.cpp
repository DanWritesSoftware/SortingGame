#include "display.h"

Display::Display(Glass ip1, Glass ip2, Glass ip3, Glass ip4) {
	p1 = ip1;
	p2 = ip2;
	p3 = ip3;
	p4 = ip4;
}

void Display::updateOut() {
	std::cout << "\n\n\n\n\n";
	std::cout << " 1    2    3    4\n";
	std::cout << "___  ___  ___  ___\n";
	for (int i = 0; i < 5; i++) {
		std::cout << '|' << p1.getContents()[i] << "|  |" << p2.getContents()[i] << "|  |" << p3.getContents()[i] << "|  |" << p4.getContents()[i] << "|\n";
	}
	std::cout << " -    -    -    - \n";
}

void Display::updateData(Glass ip1, Glass ip2, Glass ip3, Glass ip4) {
	p1 = ip1;
	p2 = ip2;
	p3 = ip3;
	p4 = ip4;
}

void Display::displayInputError() {
	std::cout << "\n\n-------------------------------\n";
	std::cout << "Invalid Input Please Try Again.\n";
	std::cout << "-------------------------------\n\n";
}

void Display::displayUnknownError() {
	std::cout << "\n\n-----------------------\n";
	std::cout << "Unknown Error Occurred.\n";
	std::cout << "-----------------------\n\n";
}
