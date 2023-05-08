#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle() {

	make = "COP3503";
	model = "Rust Bucket";
	year = 1900;
	price = 0.00;
	miles = 0;
}

Vehicle::Vehicle(string make1, string model1, int year1, float price1, int miles1) {

	make = make1;
	model = model1;
	year = year1;
	price = price1;
	miles = miles1;
}

float Vehicle::GetPrice() {

	price = (int)(price * 100 + .5);
	price = (float)price / 100;

	return price;
}

int Vehicle::GetMiles() {

	return miles;
}

string Vehicle::GetYearMakeModel() {

	string display3 = to_string(year) + " " + make + " " + model;
	return display3;
}

void Vehicle::Display() {

	cout << year << " " << make << " " << model << " $" << GetPrice() << " " << miles << endl;
}