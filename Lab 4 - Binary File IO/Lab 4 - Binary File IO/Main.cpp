#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class armaments {

	public:

		armaments();
		armaments(string weaponName_, int powerRating_, float powerConsum_);

		string weaponName;
		int powerRating;
		float powerConsum;

};

class starship {

	public:

		starship(string name_, string type_, short length_, int shields_, float warp_, int weaponCount_, vector<armaments> arms_);

		int getWeaponCount();
		int getFirePower();
		int getPowerRating();
		void print();

	private:

		string name;
		string type;
		short length;
		int shields;
		float warp;
		vector<armaments> arms;
		int weaponCount;

};

starship::starship(string name_, string type_, short length_, int shields_, float warp_, int weaponCount_, vector<armaments> arms_) {

	name = name_;
	type = type_;
	length = length_;
	shields = shields_;
	warp = warp_;
	arms = arms_;
	weaponCount = weaponCount_;

}

armaments::armaments() {

	weaponName = "Unarmed";

}

armaments::armaments(string weaponName_, int powerRating_, float powerConsum_) {

	weaponName = weaponName_;
	powerRating = powerRating_;
	powerConsum = powerConsum_;

}

int starship::getWeaponCount() {

	return weaponCount;

}

int starship::getFirePower() {

	int firepower = 0;

	if (weaponCount > 0) {

		for (int i = 0; i < weaponCount; i++) {

			firepower += arms.at(i).powerRating;

		}

	}

	return firepower;

}

int starship::getPowerRating() {

	int highestPowerRating = 0;
	int count = 0;

	for (int i = 0; i < weaponCount; i++) {

		if (arms.at(i).powerRating > highestPowerRating) {

			highestPowerRating = arms.at(i).powerRating;
			count = i;

		}

	}

	return arms.at(count).powerRating;

}

void starship::print() {

	int firepower = 0;

	cout << endl << "Name: " << name << endl;
	cout << "Class: " << type << endl;
	cout << "Length: " << length << endl;
	cout << "Shield capacity: " << shields << endl;
	cout << "Maximum Warp: " << warp << endl;
	cout << "Armaments:" << endl;

	if (weaponCount > 0) {

		for (int i = 0; i < weaponCount; i++) {

			cout << arms.at(i).weaponName << ", " << arms.at(i).powerRating << ", " << arms.at(i).powerConsum << endl;

			firepower += arms.at(i).powerRating;

		}

		cout << "Total firepower: " << firepower << endl;

	} else {

		cout << arms.at(0).weaponName << endl;

	}

}

vector<starship> loadStarships(vector<starship> fleet, unsigned int option) {

	int count;
	string filepath;

	if (option == 1) {

		filepath = "friendlyships.shp";

	} 
	else if (option == 2) {

		filepath = "enemyships.shp";

	}

	ifstream shipfile(filepath, ios_base::binary);
	shipfile.read((char*)&count, 4);

	//cout << endl << "Fleet Size: " << count << endl;

	for (int i = 0; i < count; i++) {

		// temporary variable initialization
		string nameT;
		int nameLength = 0;
		string typeT;
		int typeLength = 0;
		
		short lengthT = 0;
		int shieldsT = 0;
		float warpT = 0;
		int weaponCountT = 0;

		string weaponT;
		int weaponLength;
		int powerRatingT;
		float powerConsumT;

		// reading ship's name length
		shipfile.read((char*) &nameLength, 4);
		//cout << endl << "Length of Ship Name: " << nameLength << endl;

		// reading ship's name and turning it to string
		char* tempName = new char[nameLength];

		for (int n = 0; n < (nameLength); n++) {

			shipfile.read(&tempName[n], 1);

		}

		nameT = tempName;
		delete[] tempName;

		//cout << "Ship Name: " << nameT << endl;

		// reading ship's type length
		shipfile.read((char*) &typeLength, 4);
		//cout << "Length of Type Name: " << typeLength << endl;

		// reading ship's name and turning it to string
		char* tempType = new char[typeLength];
		
		for (int n = 0; n < (typeLength ); n++) {

			shipfile.read(&tempType[n], 1);

		}

		typeT = tempType;
		delete[] tempType;

		//cout << "Type Name: " << typeT << endl;

		// reading ship's length, shields, warp, and weaponCount
		shipfile.read((char*) &lengthT, 2);
		//cout << "Length: " << lengthT << endl;
		
		shipfile.read((char*) &shieldsT, 4);
		//cout << "Shields: " << shieldsT << endl;

		shipfile.read((char*) &warpT, 4);
		//cout << "Warp: " << warpT << endl;

		shipfile.read((char*) &weaponCountT, 4);
		//cout << "Weapon Count: " << weaponCountT << endl;

		vector<armaments> weapons;

		if (weaponCountT > 0) {

			for (int i = 0; i < weaponCountT; i++) {

				// reading ship's weapon length
				shipfile.read((char*)&weaponLength, 4);
				//cout << "Length of Type Name: " << weaponLength << endl;

				// reading ship's weapon name and turning it to string
				char* tempWeapon = new char[weaponLength];

				for (int n = 0; n < (weaponLength); n++) {

					shipfile.read(&tempWeapon[n], 1);

				}

				weaponT = tempWeapon;
				delete[] tempWeapon;

				//cout << "Type Name: " << weaponT << endl;

				shipfile.read((char*)&powerRatingT, 4);
				//cout << "Power Rating: " << powerRatingT << endl;

				shipfile.read((char*)&powerConsumT, 4);
				//cout << "Power Consumption: " << powerConsumT << endl;

				armaments arms = armaments(weaponT, powerRatingT, powerConsumT);
				weapons.push_back(arms);

			}

		} else {

			armaments arms = armaments();
			weapons.push_back(arms);

		}

		starship ship = starship(nameT, typeT, lengthT, shieldsT, warpT, weaponCountT, weapons);
		fleet.push_back(ship);

	}

	return fleet;

}

int main() {

	unsigned int option;
	vector<starship> fleet;

	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	cin >> option;

	/* Load files here */

	if (option == 1) {

		fleet = loadStarships(fleet, 1);

	} else if (option == 2) {

		fleet = loadStarships(fleet, 2);

	} else if (option == 3) {

		fleet = loadStarships(fleet, 1);
		fleet = loadStarships(fleet, 2);

	}

	cout << endl << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */

	if (option == 1) {

		for (long unsigned int i = 0; i < fleet.size(); i++) {

			fleet.at(i).print();

		}

	} else if (option == 2) {

		int count = 0;
		int power = 0;

		for (long unsigned int i = 0; i < fleet.size(); i++) {

			if (fleet.at(i).getWeaponCount() != 0) {

				for (long unsigned int n = 0; n < fleet.size(); n++) {

					int temp = fleet.at(i).getPowerRating();

					if (temp > power) {

						power = temp;
						count = i;

					}

				}

			}

		}

		fleet.at(count).print();

	} else if (option == 3) {

		int count = 0;
		int power = 0;

		for (long unsigned int i = 0; i < fleet.size(); i++) {

			if (fleet.at(i).getWeaponCount() != 0) {

				for (long unsigned int n = 0; n < fleet.size(); n++) {

					int temp = fleet.at(i).getFirePower();

					if (temp > power) {

						power = temp;
						count = i;

					}

				}

			}

		}

		fleet.at(count).print();

	} else if (option == 4) {

		int count = 0;
		int power = 9999;

		for (long unsigned int i = 0; i < fleet.size(); i++) {

			if (fleet.at(i).getWeaponCount() != 0) {

				for (long unsigned int n = 0; n < fleet.size(); n++) {

					int temp = fleet.at(i).getFirePower();

					if (temp < power) {

						power = temp;
						count = i;

					}

				}

			}

		}

		fleet.at(count).print();

	} else if (option == 5) {

		for (long unsigned int i = 0; i < fleet.size(); i++) {

			if (fleet.at(i).getWeaponCount() == 0) {

				fleet.at(i).print();

			}

		}

	}

	return 0;
}