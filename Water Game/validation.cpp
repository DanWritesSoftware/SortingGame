#include "validation.h"

Validation::Validation() {}

bool Validation::validateSingleIntInput(std::string input) {
	// Check if the string is empty
	if (input.empty()) {
		return false;
	}
	// check for int
	if (!std::isdigit(input[0])) {
		return false;
	}
	if (std::stoi(input) > 4) {
		return false;
	}
	return true;
}

