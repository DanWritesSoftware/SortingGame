#include "glass.h"
//#include <iostream>


Glass::Glass() {

}

Glass::Glass(std::array<int, 5> state) {
	this->contents = state;
}

std::array<int,5>& Glass::getContents() {
	return this->contents;
}

std::string Glass::getString() {
	std::string output;
	for (int i = 0; i < 5; i++) {
		std::array<int, 5> contents = this->getContents();
		int number = contents[i];
		output += std::to_string(number);
	}
	return output;
}

int Glass::getSpace() {
	std::array<int, 5> contents = this->getContents();
	int output = 0;
	for (int i = 0; i < 5; i++) {
		int number = contents[i];
		if (number == 0) {
			output++;
		}
		else { return output; }
	}
	return output;
}

int Glass::getTopNumber() {
	std::array<int, 5> contents = this->getContents();
	for (int i = 0; i < 5; i++) {
		int number = contents[i];
		if (number != 0) {
			return contents[i];
		}
	}
	return 0;
}

void Glass::setTopNumber(int number) {
	std::array<int, 5>& contents = this->getContents(); // get a reference to the contents
	for (int i = 0; i < 5; i++) {
		if (contents[i] != 0) {
			contents[i] = number;
			break;
		}
	}
}

void Glass::setTopZero(int number) {


}

void Glass::add(Glass& other) {
	std::array<int, 5>& contents = this->getContents();
	std::array<int, 5>& otherContents = other.getContents();
	int mySpace = this->getSpace();
	int top = other.getTopNumber();
	for (int i = 0; i < mySpace; i++) {
		if (other.getTopNumber() == top) {
			add(top);
			other.setTopNumber(0);
			//std::cout << "this:  " << this->getString() << '\n' << "other: " << other.getString() << "\n\n";
		}
		else { break; }
	}
}

void Glass::add(int number) {
	std::array<int, 5>& contents = this->getContents();
	contents[getSpace()-1] = number;
}

bool Glass::isComplete() {
	std::array<int, 5>& contents = this->getContents();
	for (int i = 0; i < 5; i++) {
		if (contents[4] == contents[i] || contents[i] == 0) {
			continue;
		}
		else { return false; }
	}
	return true;
}