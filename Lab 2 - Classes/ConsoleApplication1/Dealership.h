#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"
#include "Showroom.h"
using namespace std;

class Dealership {

private:

	string name;
	unsigned int capacity;
	float averageCarPrice;

	vector<Showroom> inventory;

public:

	Dealership();
	Dealership(string name1, unsigned int capacity1);

	void AddShowroom(Showroom);
	float GetAveragePrice();
	void ShowInventory();
};
