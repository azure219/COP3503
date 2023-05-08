#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"
using namespace std;

class Showroom {

private:

	string name;
	unsigned int capacity;

	vector<Vehicle> inventory;

public:

	Showroom();
	Showroom(string name1, unsigned int capacity1);

	void AddVehicle(Vehicle);
	void ShowroomInventory();
	float GetInventoryValue();
	int GetSize();
	int GetCapacity();
};