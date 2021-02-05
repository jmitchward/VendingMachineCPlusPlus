#pragma once
#include "userIO.h"

class machineInput : virtual public userIO {
public:
	void userIO::print(std::string message) override;
	void userIO::print(const char message) override;
	float userIO::readFloat(std::string prompt) override;
	int userIO::readInt(std::string prompt) override;
	long userIO::readLong(std::string prompt) override;
	std::string userIO::readString(std::string prompt) override;
};