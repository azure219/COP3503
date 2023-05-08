#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class welcomeWindow {

	private:

		int dimensions[3];
		
		int height;
		int width;

		string scores;

	public:

		bool openNextWindow = false;
		string playerName;

		welcomeWindow() {

		}

		void runWW();
		void runLW();

		int returnHeight();
		int returnWidth();
		int returnMineCount();
		int returnTileCount();
		sf::Font returnFont();

};