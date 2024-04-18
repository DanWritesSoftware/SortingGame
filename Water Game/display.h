#ifndef DISPLAY_H
#define DISPLAY_H
#include "glass.h"
#include <iostream>
#include <map>
#include <vector>

class Display {
public:
	Display(Glass ip1,Glass ip2,Glass ip3,Glass ip4);
	Display(std::map<int, Glass> igameState);
	void updateOut();
	void updateData(Glass ip1, Glass ip2, Glass ip3, Glass ip4);
	void updateData(std::map<int, Glass> igameState);
	void displayInputError();
	void displayUnknownError();

private:
	Glass p1,p2,p3,p4;
	std::map<int, Glass> gameState;

};


#endif // !DISPLAY_H

