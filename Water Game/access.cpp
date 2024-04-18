#include "access.h"

std::map<int, Glass> Access::readLevel() {

	std::map<int, Glass> output;
	// get level data as vector
	std::string lineData;
	std::vector<int> dataVector;
	if (dataIn.is_open()) {
		while (std::getline(dataIn, lineData, ',')) {
			dataVector.push_back(std::stoi(lineData));
			//std::cout << lineData << '\n';
		}
	}
	else {
		std::cerr << "FILE OPEN ERROR"; // TODO implement proper error handling
	}

	int spacer = 3;
	for (int i = 0; i < dataVector[1]; i++) { // TODO add check for data to avoid input out of bounds
		output.insert(std::pair<int, Glass>(i, Glass({ dataVector[spacer], dataVector[spacer + 1], dataVector[spacer + 2], dataVector[spacer + 3], dataVector[spacer + 4] })));
		spacer = spacer + 5;
	}

	//dataIn.close();
	return output;
}

void Access::writeHighScore(int score) {

}
