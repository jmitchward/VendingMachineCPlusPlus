#include "machineService.h"

machineService::machineService() {

}

machineService::machineService(machineDAO& dao) {
	this->dao = dao;
	this->userTotal = NULL;
}

machineItem machineService::purchaseItem(std::string& itemId) {
	if (this->userTotal == NULL) {
		throw 0;
	}
	else if (this->userTotal < dao.getItem(itemId)->getCost()) {
		throw 1;
	}
	else if (dao.getItem(itemId)->getStock() == 0) {
		throw 2;
	}
	else {
		dao.updateStock(itemId);
		userTotal = userTotal - dao.getItem(itemId)->getCost();
		return *dao.getItem(itemId);
	}
}

void machineService::addItem(machineItem& item) {
	if (dao.getItem(item.getItemId()) != nullptr) {
		throw 0;
	}
	else {
			validateAdminAdd(item);
			dao.addItem(item);
		} 
}

std::string machineService::requestId() {
	return dao.newId();
}

void machineService::validateAdminAdd(machineItem& item) {
	if (item.getName() == ""
		|| item.getStock() == 0
		|| item.getCost() == 0
		|| item.getItemId() == "") {
		throw 0;
	}
}

std::vector<machineItem> machineService::displayItems() {
	std::vector<machineItem> itemsInStock;
	for (machineItem item : dao.getAllItems()) {
		if (item.getStock() >= 1) {
			itemsInStock.push_back(item);
		}
	}
	return itemsInStock;
}

machineItem machineService::getItem(std::string& itemId) {
	return *dao.getItem(itemId);
}

double machineService::checkTotal() {
	return userTotal;
}

void machineService::setTotal(double total) {
	if (userTotal != 0) {
		userTotal = userTotal + total;
	}
	else {
		userTotal = total;
	}

}

std::vector<int> machineService::returnChange() {
	double remain = 0;
	std::vector<int> change;
	change.push_back(int(userTotal / 0.25));
	remain = (std::fmod(userTotal, 0.25));
	if (remain != 0.00) {
		change.push_back(int(remain / 0.10));
		remain = (std::fmod(userTotal, 0.10));
		if (remain != 0.00) {
			change.push_back(int(remain / 0.05));
			remain = (std::fmod(userTotal, 0.05));
			if (remain != 0.00) {
				change.push_back(int(remain / 0.01));
			} else {
				change.push_back(0);
			}
		} else {
			change.push_back(0);
		}
	} else {
		change.push_back(0);
	}
	return change;
}


void machineService::exitCascade() {
	dao.runInventory();
}