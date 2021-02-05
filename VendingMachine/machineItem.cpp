#include <iostream>
#include "machineItem.h"

machineItem::machineItem() {

}

machineItem::machineItem(std::string id, std::string name, double cost, int stock) {
	itemId = id;
	itemName = name;
	itemCost = cost;
	itemStock = stock;
}

std::string machineItem::getItemId() {
	return itemId;
}

std::string machineItem::getName() {
	return itemName;
}

double machineItem::getCost() {
	return itemCost;
}

int machineItem::getStock() {
	return itemStock;
}

void machineItem::setStock(int newStock) {
	itemStock = newStock;
}