#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

mt19937 random_mt;

class State {

	public:

		State() {

			name = "";
			perCapitaIncome = 0;
			population = 0;
			medianIncome = 0;
			numHouseholds = 0;

		}

		State(string n, int pci, int p, int mi, int nh) {

			name = n;
			perCapitaIncome = pci;
			population = p;
			medianIncome = mi;
			numHouseholds = nh;

		}

		string name;
		int perCapitaIncome;
		int population;
		int medianIncome;
		int numHouseholds;

};

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides) {

	map<int, int> rolls;

	for (int i = 1; i <= numberOfSides; i++) {

		rolls[i] = 0;

	}

	for (int i = 0; i < numberOfRolls; i++) {

		int r = Random(1, numberOfSides);
		rolls[r] = rolls[r] + 1;

	}

	map<int, int>::iterator it;

	for (it = rolls.begin(); it != rolls.end(); it++) {

		cout << it->first << ": " << it->second << endl;

	}

}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);


		cout << "Number of times to roll the die: ";
		int numRolls;
		cin >> numRolls; // user input

		cout << "Number of sides on this die: ";
		int numSides;
		cin >> numSides; // user input

		RollDice(numRolls, numSides); // Roll Dice

	}
	else if (option == 2)
	{
		// Load the states
		map<string, State> states;

		string nameT;
		int perCapitaIncomeT;
		int populationT;
		int medianIncomeT;
		int numHouseholdsT;

		ifstream file("states.csv");
		string line;

		getline(file, line);

		while (getline(file, line)) {

			stringstream ss(line);
			string data;

			while (getline(ss, data, ',')) {

				nameT = data;

				getline(ss, data, ',');
				perCapitaIncomeT = stoi(data);

				getline(ss, data, ',');
				populationT = stoi(data);

				getline(ss, data, ',');
				medianIncomeT = stoi(data);

				getline(ss, data, ',');
				numHouseholdsT = stoi(data);

				State temp = State(nameT, perCapitaIncomeT, populationT, medianIncomeT, numHouseholdsT);

				states.emplace(nameT, temp);

			}

		}

		// Get input for option 1 (show all states) or 2 (do a search for a particular state)

		cout << "1. Print all the states\n";
		cout << "2. Search for a state\n";

		int option2;
		cin >> option2;

		if (option2 == 1) { // prints all

			map<string, State>::iterator it;

			for (it = states.begin(); it != states.end(); it++) {

				cout << it->second.name << endl;
				cout << "Population: " << it->second.population << endl;
				cout << "Per Capita Income: " << it->second.perCapitaIncome << endl;
				cout << "Median household income: " << it->second.medianIncome << endl;
				cout << "Number of households: " << it->second.numHouseholds << endl;

			}

		} else if (option2 == 2) { // prints specific

			string specific;
			cin >> specific;

			if (states.find(specific) == states.end()) {

				cout << "No match found for " << specific << endl;

			} else {

				cout << states.find(specific)->second.name << endl;
				cout << "Population: " << states.find(specific)->second.population << endl;
				cout << "Per Capita Income: " << states.find(specific)->second.perCapitaIncome << endl;
				cout << "Median household income: " << states.find(specific)->second.medianIncome << endl;
				cout << "Number of households: " << states.find(specific)->second.numHouseholds << endl;
			
			}

		}

	}

	return 0;
}
