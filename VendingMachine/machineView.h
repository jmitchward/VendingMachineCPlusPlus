#pragma once

#ifndef MACHINEVIEW_H
#define MACHINEVIEW_H


#include <iostream>
#include <vector>
#include <optional>
#include <unordered_map>
#include "abstractMachineDAO.h"
#include "machineInput.h"
#include "machineItem.h"

class machineView
{
private:
	machineInput getInput;
public:
	machineView();
	machineView(machineInput newInput);
	std::string getMenu(std::vector<machineItem> menuItems);
	machineItem getItems(std::string nextItemId);
	double getMoney();
	void vendItem(std::string name);
	void vendSuccess(machineItem purchased, std::vector<double> change);
	void displayError(std::string message);
	void displayExit();
	void displayMoney(double money);
};

#endif

