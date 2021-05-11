#include "pch.h"
#include "CppUnitTest.h"
#include "../VendingMachine/machineDAO.h"
#include "../VendingMachine/machineItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VendingTests
{
	TEST_CLASS(VendingTests)
	{
	public:
		
		TEST_METHOD(addItem)
		{
			// Assign
			std::string id = "001";
			std::string name = "Apples";
			double cost = 10.00;
			int stock = 10;

			// Act
			machineItem testItem(id, name, cost, stock);
			machineDAO testDao;
			testDao.addItem(testItem);
			machineItem* retrievedItem = testDao.getItem(id);

			// Assert
			Assert::AreEqual(id, retrievedItem->getItemId());
			Assert::AreEqual(name, retrievedItem->getName());
			Assert::AreEqual(cost, retrievedItem->getCost());
			Assert::AreEqual(stock, retrievedItem->getStock());
		}

		TEST_METHOD(newID)
		{
			// Assign
			std::string expected = "001";

			// Act
			machineDAO testDao;
			std::string returnedId = testDao.newId();

			// Assert
			Assert::AreEqual(expected, returnedId);
		}

		TEST_METHOD(updateStock) 
		{
			// Assign
			std::string id = "001";
			std::string name = "Apples";
			double cost = 10.00;
			int stock = 10;
			int expected = 9;

			// Act
			machineItem testItem(id, name, cost, stock);
			machineDAO testDao;
			testDao.addItem(testItem);
			testDao.updateStock(id);

			// Assert
			Assert::AreEqual(expected, testDao.getItem(testItem.getItemId())->getStock());
		}

		TEST_METHOD(getAllItems) 
		{
			// Assign
			std::string idA = "001";
			std::string nameA = "Apples";
			double costA = 10.00;
			int stockA = 10;

			std::string idB = "002";
			std::string nameB = "Oranges";
			double costB = 5.00;
			int stockB = 20;

			// Act
			machineItem testItemA(idA, nameA, costA, stockA);
			machineItem testItemB(idB, nameB, costB, stockB);
			machineDAO testDao;
			std::vector<machineItem> retrievedItems;
			testDao.addItem(testItemA);
			testDao.addItem(testItemB);
			retrievedItems = testDao.getAllItems();

			// Assert
			Assert::AreEqual((int) retrievedItems.size(), 2);
		}
	};
}
