#pragma once
#include <iostream>
#include <string>
#include <optional>
#include "machineView.h"
#include "machineService.h"

class machineController {
private:
	machineView view;
	machineService service;
public:
	machineController(machineView view, machineService service);
	void programStart();
	void purchaseChain(std::string itemId);
	void enterMoney();
	void exitChain();
	void insertItems();
	void checkMoney();
};
