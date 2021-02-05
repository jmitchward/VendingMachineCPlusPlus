#include "machineInput.h"

void machineInput::print(std::string message) {
	std::cout << message << std::endl;
}

void machineInput::print(const char message) {
	std::cout << message << std::endl;
}

float machineInput::readFloat(std::string prompt) {
	bool invalidInput = true;
	float num = 0;
	while (invalidInput) {
		try {
			std::string stringValue = this->readString(prompt);
			num = std::stof(stringValue);
			invalidInput = false;
		}
		catch (std::invalid_argument) {
			this->print("Input error. Please try again");
		}
	}
	return num;
}

int machineInput::readInt(std::string prompt) {
	bool invalidInput = true;
	int num = 0;
	while (invalidInput) {
		try {
			std::string stringValue = this->readString(prompt);
			num = std::stoi(stringValue);
			invalidInput = false;
		}
		catch (std::invalid_argument) {
			this->print("Input error. Please try again");
		}
	}
	return num;
}

long machineInput::readLong(std::string prompt) {
	bool invalidInput = true;
	long num = 0;
	while (invalidInput) {
		try {
			std::string stringValue = this->readString(prompt);
			num = std::stol(stringValue);
			invalidInput = false;
		}
		catch (std::invalid_argument) {
			this->print("Input error. Please try again");
		}
	}
	return num;
}
	
std::string machineInput::readString(std::string prompt) {
	std::string str;
	std::cout << prompt;
	std::cin >> str;
	return str;
}
	

