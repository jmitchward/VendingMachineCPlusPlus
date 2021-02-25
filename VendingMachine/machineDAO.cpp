#include "machineDAO.h"


machineItem machineDAO::addItem(machineItem item) {
	inventory.insert(std::make_pair(item.getItemId(), item));
	return item;
}

std::string machineDAO::newId() {
	std::stringstream newId;
	std::string appendee;
	if (nextId <= 9) {
		appendee = "00";
	}
	else if (nextId <= 99) {
		appendee = "0";
	}
	else {
		appendee = "";
	}
	newId << appendee << std::to_string(nextId);
	return newId.str();
}

void machineDAO::updateStock(std::string itemId) {
	inventory.at(itemId).setStock(inventory.at(itemId).getStock() - 1);
}

machineItem* machineDAO::getItem(std::string itemId) {
	if (inventory.find(itemId) == inventory.end()) {
		return nullptr;
	}
	else {
		return &inventory.at(itemId);
	}
}

std::vector<machineItem> machineDAO::getAllItems() {
	std::vector<machineItem> allItems;
	for (auto item : inventory) {
		allItems.push_back(item.second);
	}
	return allItems;
}


void machineDAO::runInventory() {
	saveInventory();
}

void machineDAO::saveInventory() {

}

void machineDAO::sqlConnect() {

}