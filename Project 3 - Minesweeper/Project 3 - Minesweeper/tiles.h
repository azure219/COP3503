//#include <iostream>
//#include <iomanip>
//#include <random>
//#include <vector>
//#include <SFML/Graphics.hpp>
//using namespace std;
//
//class tile {
//
//	private:
//
//		sf::Sprite background;
//		sf::Sprite foreground;
//		sf::Sprite topIcon;
//		sf::Sprite flagIcon;
//
//		bool debug;
//
//	public:
//
//		vector<tile*> neighboring;
//
//		int mines;
//		int flags;
//		bool isMine;
//		bool hasFlag;
//		bool revealed;
//
//		tile(map<string, sf::Texture>& texture, float x, float y);
//
//		void createMine(bool bombstate);
//		void updateIcon(map<string, sf::Texture>& textures);
//
//		bool Flag();
//		void Debug();
//		bool Reveal(int& counter);
//
//		void Create(sf::RenderWindow& window);
//
//};