#pragma once
#ifndef USERIO_H
#define USERIO_H

#include <iostream>
#include <string>

class userIO
{
public:
	virtual void print(std::string message) = 0;
	virtual void print(const char message) = 0;
	virtual float readFloat(std::string prompt) = 0;
	virtual int readInt(std::string prompt) = 0;
	virtual long readLong(std::string prompt) = 0;
	virtual std::string readString(std::string prompt) = 0;
};

#endif

