#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "machineItem.h"
#include "machineView.h"


class abstractMachineDAO {
public:
	virtual machineItem addItem(machineItem item) = 0;
	virtual std::string newId() = 0;
	virtual void updateStock(std::string itemId) = 0;
	virtual machineItem* getItem(std::string itemId) = 0;
	virtual std::vector<machineItem> getAllItems() = 0;
	virtual void runInventory() = 0;
	virtual void saveInventory() = 0;
	virtual void sqlConnect() = 0;
};