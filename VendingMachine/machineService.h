#pragma once
#include "abstractMachineService.h"


class machineService : virtual public abstractMachineService {
private:
	machineDAO dao;
	double userTotal;
	double quarterTotal;
	double dimeTotal;
	double nickleTotal;
	double pennyTotal;
public:
	machineService();
	machineService(machineDAO& dao);
	machineItem purchaseItem(std::string& itemId) override;
	void addItem(machineItem& item) override;
	std::string requestId() override;
	void validateAdminAdd(machineItem& item) override;
	std::vector<machineItem> displayItems() override;
	machineItem getItem(std::string& itemId) override;
	double checkTotal() override;
	void setTotal(double total) override;
	std::vector<int> returnChange() override;
	void exitCascade() override;
};