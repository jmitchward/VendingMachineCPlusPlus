#include "machineController.h"

machineController::machineController(machineView view, machineService service) {
	this->view = view;
	this->service = service;
}

void machineController::programStart() {
	view.displayMoney(service.checkTotal());
	std::string menuSelect = view.getMenu(service.displayItems());
	if (menuSelect == "0") {
		enterMoney();
	}
	else if (menuSelect == "-1") {
		exitChain();
	}
	else if (menuSelect == "-2") {
		insertItems();
	}
	else if (&service.getItem(menuSelect) != nullptr) {
		checkMoney();
		purchaseChain(menuSelect);
	}
	else {
		view.displayError("Invalid selection.");
		programStart();
	}
	programStart();
}

void machineController::purchaseChain(std::string itemId) {
	view.vendItem(service.getItem(itemId).getName());
	try {
		service.purchaseItem(itemId);
	}
	catch (int error) {
		switch (error) {
			case 0:
				view.displayError("Please enter funds.");
				programStart();
			case 1:
				view.displayError("Insufficient funds.");
				programStart();
			case 2:
				view.displayError("Item out of stock.");
				programStart();
			}
	}
}

void machineController::enterMoney() {
	std::optional<double> money = view.getMoney();
	if (money.has_value()) {
		service.setTotal(*money);
	}
	
}

void machineController::exitChain() {
	view.displayExit();
	service.exitCascade();

}

void machineController::insertItems() {
	std::string newItemId = service.requestId();
	machineItem newItem = view.getItems(newItemId);
	try {
		service.addItem(newItem);
	}
	catch (int error) {
		view.displayError("Invalid ID.");
		view.getItems(newItemId);
	}

}

void machineController::checkMoney() {
	service.checkTotal();
}