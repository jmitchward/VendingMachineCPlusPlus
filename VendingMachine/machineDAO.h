#pragma once
#include "abstractMachineDAO.h"
#include "mysql_driver.h"
#include "mysql_connection.h"


class machineDAO : virtual public abstractMachineDAO {
private:
	std::unordered_map<std::string, machineItem> inventory;
	int nextId = 1;
	sql::mysql
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
