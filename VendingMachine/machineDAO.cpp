#include "machineDAO.h"


machineItem machineDAO::addItem(machineItem item) {
	inventory.insert(std::make_pair(item.getItemId(), item));
	return item;
}

std::string machineDAO::newId() {
	char id[3];
	sprintf_s(id, "00%d", nextId+1);
	return id;
}

void machineDAO::updateStock(std::string itemId) {
	inventory.at(itemId).setStock(inventory.at(itemId).getStock() - 1);
}

machineItem* machineDAO::getItem(std::string itemId) {
	std::optional<machineItem> foundItem = inventory.at(itemId);
	if (foundItem.has_value()) {
		return &inventory.at(itemId);
	}
	else {
		return nullptr;
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