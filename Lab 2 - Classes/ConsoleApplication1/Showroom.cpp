#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"
#include "Showroom.h"
using namespace std;

Showroom::Showroom() {

	name = "Unnamed Showroom";
	capacity = 0;
}

Showroom::Showroom(string name1, unsigned int capacity1) {

	name = name1;
	capacity = capacity1;
}

int Showroom::GetSize() {

	return inventory.size();
}

int Showroom::GetCapacity() {

	return capacity;
}

void Showroom::AddVehicle(Vehicle vehicle1) {

	if (capacity != inventory.size()) {

		inventory.push_back(vehicle1);
	}
	else {

		string error = "Showroom is full! Cannot add " + vehicle1.GetYearMakeModel();
		cout << error << endl;
	}
}

void Showroom::ShowroomInventory() {

	if (inventory.size() == 0) {

		cout << name << " is empty!" << endl;

	} else {

		cout << "Vehicles in " << name << endl;

		for (int n = 0; n < inventory.size(); n++) {

			inventory[n].Display();
		}

		cout << endl;
	}
}

float Showroom::GetInventoryValue() {

	float inventoryValue = 0;

	for(int n = 0; n < inventory.size(); n++) {

		float price = inventory[n].GetPrice();
		inventoryValue = inventoryValue + price;
	}

	inventoryValue = (int)(inventoryValue * 100 + .5);
	return (float)inventoryValue / 100;

}