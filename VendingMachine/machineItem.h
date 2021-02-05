#pragma once
#include <iostream>
class machineItem {
private:
	std::string itemId;
	std::string itemName;
	double itemCost;
	int itemStock;
public:
	machineItem();
	machineItem(std::string itemId, std::string name, double cost, int stock);
	std::string getItemId();
	std::string getName();
	double getCost();
	int getStock();
	void setStock(int newStock);
};