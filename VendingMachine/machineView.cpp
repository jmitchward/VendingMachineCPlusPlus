#include "machineView.h"
#include "machineInput.h"
#include "userIO.h"
#include <vector>
#include <iostream>

machineView::machineView() {

}

machineView::machineView(machineInput newInput) {
	getInput = newInput;
}

std::string machineView::getMenu(std::vector<machineItem> menuItems) {
	getInput.print("Main Menu:");
	for (auto& item : menuItems) {
		getInput.print(item.getItemId() + " | " + item.getName() + " | " + std::to_string(item.getCost()));
	}
	getInput.print("0. Enter Money ");
	getInput.print("-1. Exit: ");
	return getInput.readString("Please make a selection: ");
}

machineItem machineView::getItems(std::string nextItemId) {
	getInput.print("Admin Add");
	std::string itemId = nextItemId;
	std::string itemName = getInput.readString("Item Name: ");
	float itemCost = getInput.readFloat("Item Cost: ");
	int itemStock = getInput.readInt("Item Stock: ");
	machineItem newItem(itemId, itemName, itemCost, itemStock);
	/* Pointer variable storing the newly created machine item. */
	return newItem;
	/* Return the value to the controller. */
}

double machineView::getMoney() {
	return getInput.readFloat("How much would you like to put in: ");
}

void machineView::vendItem(std::string name) {
	getInput.print("Vending " + name + "...");
}

void machineView::vendSuccess(machineItem purchased, std::vector<double> change) {
	getInput.print("Please enjoy your " + purchased.getName());
	getInput.print("Your change:");

}

void machineView::displayError(std::string message) {
	getInput.print("An error has occured.");
	getInput.print(message);
}

void machineView::displayExit() {
	getInput.print("Thank you for vending with us.");
}

void machineView::displayMoney(double money) {
	getInput.print("Current Amount: $" + std::to_string(money));
}





