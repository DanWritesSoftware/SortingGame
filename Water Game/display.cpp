#include "display.h"

Display::Display(Glass ip1, Glass ip2, Glass ip3, Glass ip4) {
	p1 = ip1;
	p2 = ip2;
	p3 = ip3;
	p4 = ip4;
}

void Display::updateOut() {
	std::cout << "\n\n\n\n\n";
	for (int i = 0; i < 5; i++) {
		std::cout << '|' << p1.getContents()[i] << "|  |" << p2.getContents()[i] << "|  |" << p3.getContents()[i] << "|  |" << p4.getContents()[i] << "|\n";
	}
}

void Display::updateData(Glass ip1, Glass ip2, Glass ip3, Glass ip4) {
	p1 = ip1;
	p2 = ip2;
	p3 = ip3;
	p4 = ip4;
}