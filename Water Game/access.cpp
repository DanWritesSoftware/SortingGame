#include "access.h"

std::map<int, Glass> Access::readLevel() {

	std::map<int, Glass> output;
	// get level data as vector
	std::string lineData;
	std::vector<int> dataVector;
	if (dataIn.is_open()) {
		if (!dataIn.good()) {
			std::cerr << "DATA STATE ERROR\n"; // TODO implement proper error handling
			if (dataIn.eof()) {
				std::cerr << "DATA END OF FILE ERROR (eofbit)\n";
			}
			if (dataIn.fail()) {
				std::cerr << "DATA STREAM FAILURE (failbit)\n";
			}
			if (dataIn.bad()) {
				std::cerr << "DATA STREAM BAD (badbit)\n";
			}
		}
		if (!goToLine(dataIn, currentLine)) {
			std::cerr << "DATA ERROR FAILED TO GO TO LINE\n";
		}
		dataIn.clear();
		while (std::getline(dataIn, lineData, ',')) {
			dataVector.push_back(std::stoi(lineData));
			//std::cout << lineData << '\n';
		}

	}
	else {
		std::cerr << "FILE OPEN ERROR\n"; // TODO implement proper error handling
	}

	// Check if dataVector has enough elements
	if (dataVector.size() < dataVector[1] * 5 + 2) {
		std::cerr << "DATA VECTOR SIZE ERROR"; // TODO implement proper error handling
		return output;
	}

	int spacer = 3;
	
	for (int i = 0; i < dataVector[1]; i++) { // TODO add check for data to avoid input out of bounds
		output.insert(std::pair<int, Glass>(i, Glass({ dataVector[spacer], dataVector[spacer + 1], dataVector[spacer + 2], dataVector[spacer + 3], dataVector[spacer + 4] })));
		spacer = spacer + 5;
	}

	dataVector.clear();
	currentLine++; // move to next level
	
	//dataIn.close();
	return output;
}

void Access::writeHighScore(int score) {

}

bool Access::goToLine(std::ifstream& file, int num) {
	/*
	file.seekg(std::ios::beg); // go back to beginning of file
	for (int i = 0; i < num - 1; i++) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	*/

	file.clear(); // clear any flags
	file.seekg(std::ios::beg); // go back to beginning of file
	for (int i = 0; i < num - 1; ++i) {
		if (file.ignore(std::numeric_limits<std::streamsize>::max(), '\n').eof()) {
			return false; // if we hit EOF before we find the line, return false
		}
	}
	if (file.eof()) {
		return false; // if we're at EOF after finding the line, return false
	}
	return true; // if we've found the line and we're not at EOF, return true
}
