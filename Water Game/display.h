#ifndef DISPLAY_H
#define DISPLAY_H
#include "glass.h"
#include <iostream>

class Display {
public:
	Display(Glass ip1,Glass ip2,Glass ip3,Glass ip4);
	void updateOut();
	void updateData(Glass ip1, Glass ip2, Glass ip3, Glass ip4);

private:
	Glass p1,p2,p3,p4;

};


#endif // !DISPLAY_H

