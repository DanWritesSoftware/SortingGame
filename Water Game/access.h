#ifndef ACCESS_H
#define ACCESS_H
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "glass.h"

class Access {

public:
	Access() : dataIn("data.csv") {
	// ofstream opened in append mode to not wipe data
		dataOut.open("data.csv, , std::ios::app");
	} 
	std::map<int,Glass> readLevel();
	void writeHighScore(int score);

private:
	std::ofstream dataOut;
	std::ifstream dataIn;
};


#endif
