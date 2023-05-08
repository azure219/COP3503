#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
using namespace std;

Dealership::Dealership() {

	name = "Generic Dealership";
	capacity = 0;
	averageCarPrice = 0.0;
}

Dealership::Dealership(string name1, unsigned int capacity1) {

	name = name1;
	capacity = capacity1;
}

void Dealership::AddShowroom(Showroom showroom1) {

	if (capacity != inventory.size()) {

		inventory.push_back(showroom1);
	}
	else {

		string error = "Dealership is full, can't add another showroom!";
		cout << error << endl;
	}
}

float Dealership::GetAveragePrice() {

	float inventoryValue = 0;
	int vehiclesNumber = 0;

	for (int n = 0; n < inventory.size(); n++) {

		inventoryValue = inventoryValue + inventory[n].GetInventoryValue();
		vehiclesNumber = vehiclesNumber + inventory[n].GetSize();
	}

	averageCarPrice = (inventoryValue / vehiclesNumber);

	return averageCarPrice;
}

void Dealership::ShowInventory() {

	if (inventory.size() == 0) {

		cout << name << " is empty!" << endl;
		cout << "Average car price: $" << averageCarPrice;

	} else {

		//cout << "Vehicles in " << name << endl;

		for (int n = 0; n < inventory.size(); n++) {

			inventory[n].ShowroomInventory();
		}
	
		cout << "Average car price: $" << GetAveragePrice();
	}
}