#include "display.h"

Display::Display(Glass ip1, Glass ip2, Glass ip3, Glass ip4) {
	p1 = ip1;
	p2 = ip2;
	p3 = ip3;
	p4 = ip4;
}

Display::Display(std::map<int, Glass> igameState) {
	gameState = igameState;
}

void Display::updateOut() {
	/*
	std::cout << "\n\n\n\n\n";
	std::cout << " 1    2    3    4\n";
	std::cout << "___  ___  ___  ___\n";
	for (int i = 0; i < 5; i++) {
		std::cout << '|' << p1.getContents()[i] << "|  |" << p2.getContents()[i] << "|  |" << p3.getContents()[i] << "|  |" << p4.getContents()[i] << "|\n";
	}
	std::cout << " -    -    -    - \n";
	*/
	std::string label = " ";
	int size = gameState.size();
	std::vector<std::array<int, 5>> rows; // vector is used as the number of bottles to render is not known at compile time
	for (const auto& pair : gameState) { // (1,Glass)
		int key = pair.first;
		Glass g = pair.second;
		label += std::to_string(key);
		label += "    ";
		rows.push_back(g.getContents());
		//std::cout << g.getString() << "\n";
	}
	// Render
	std::cout << label << '\n';
	for (int i = 0; i < 5; i++) {
		std::cout << "|";
		for (int j = 0; j < rows.size(); j++) {
			std::cout << rows[j][i];
			if (j == rows.size()-1) {
				std::cout << "|";
			}
			else {
				std::cout << "|  |";
			}
		}
		std::cout << '\n';
	}
	std::cout << " *    *    *    * \n";
}

void Display::updateData(Glass ip1, Glass ip2, Glass ip3, Glass ip4) {
	p1 = ip1;
	p2 = ip2;
	p3 = ip3;
	p4 = ip4;
}

void Display::updateData(std::map<int, Glass> igameState) {
	gameState = igameState;
	/*
	for (const auto& pair : igameState) {
		int key = pair.first;
		Glass g = pair.second;
		gameState.insert(std::pair<int, Glass>(key,g));
	}
	*/
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
