#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "machineItem.h"
#include "machineDAO.h"

class abstractMachineService {
	
	virtual machineItem purchaseItem(std::string& itemId) = 0;
	virtual void addItem(machineItem& item) = 0;
	virtual std::string requestId() = 0;
	virtual void validateAdminAdd(machineItem& item) = 0;
	virtual std::vector<machineItem> displayItems() = 0;
	virtual machineItem getItem(std::string& itemId) = 0;
	virtual double checkTotal() = 0;
	virtual void setTotal(double total) = 0;
	virtual std::vector<int> returnChange() = 0;
	virtual void exitCascade() = 0;
};