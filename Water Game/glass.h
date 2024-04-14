#ifndef GLASS_H
#define GLASS_H
#include <array>
#include <string>

class Glass {

public:

	Glass();
	Glass(std::array<int, 5> state);
	std::array<int,5>& getContents();
	std::string getString();
	int getSpace();
	int getTopNumber();
	void setTopNumber(int number);
	void setTopZero(int number);
	void add(Glass& other);
	void add(int number);
	bool isComplete();
	
private:

	std::array<int,5> contents = {0,0,0,0,0};

};


#endif // !GLASS_H
