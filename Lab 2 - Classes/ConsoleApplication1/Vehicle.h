#pragma once
#include <string>

using namespace std;

class Vehicle {

private:

	string make;
	string model;
	int year;
	float price;
	int miles;

public:

	Vehicle();
	Vehicle(string make1, string model1, int year1, float price1, int miles);

	string GetYearMakeModel();
	float GetPrice();
	int GetMiles();

	void Display();
};