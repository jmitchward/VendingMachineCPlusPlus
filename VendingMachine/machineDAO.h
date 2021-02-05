#pragma once
#include "abstractMachineDAO.h"


class machineDAO : virtual public abstractMachineDAO {
private:
	std::unordered_map<std::string, machineItem> inventory;
	int nextId = 1;
public:
	machineItem addItem(machineItem item) override;
	std::string newId() override;
	void updateStock(std::string itemId) override;
	machineItem* getItem(std::string itemId) override;
	std::vector<machineItem> getAllItems() override;
	void runInventory() override;
	void saveInventory() override;
	void sqlConnect() override;
};
