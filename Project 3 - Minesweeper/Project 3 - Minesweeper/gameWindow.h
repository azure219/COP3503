//#include <iostream>
//#include <iomanip>
//#include <random>
//#include <vector>
//#include <SFML/Graphics.hpp>
//#include "tiles.h"
//using namespace std;
//
//class gameWindow {
//
//	private:
//
//		vector<tile> tileboard;
//		int height;
//		int width;
//		int mines;
//
//		int flagsLeft = 50;
//		int minesLeft;
//		int tilesRevealed;
//
//		sf::Sprite reset;
//		sf::Sprite debugger;
//		sf::Sprite timer;
//
//		bool isLost;
//		bool isOver;
//
//		vector<bool> tileMineID;
//
//		static map<string, sf::Texture> textures;
//
//	public:
//
//		vector<tile> tilesVector;
//
//		gameWindow(int h, int w, int m) {
//
//			MakeTiles();
//			RandomTileIds();
//
//			height = h;
//			width = w;
//			mines = m;
//
//			textures["debug"].loadFromFile("files/images/debug.png");
//			textures["digits"].loadFromFile("files/images/digits.png");
//			textures["face_happy"].loadFromFile("files/images/face_happy.png");
//			textures["face_lose"].loadFromFile("files/images/face_lose.png");
//			textures["face_win"].loadFromFile("files/images/face_win.png");
//			textures["flag"].loadFromFile("files/images/flag.png");
//			textures["leaderboard"].loadFromFile("files/images/leaderboard.png");
//			textures["number_1"].loadFromFile("files/images/number_1.png");
//			textures["number_2"].loadFromFile("files/images/number_2.png");
//			textures["number_3"].loadFromFile("files/images/number_3.png");
//			textures["number_4"].loadFromFile("files/images/number_4.png");
//			textures["number_5"].loadFromFile("files/images/number_5.png");
//			textures["number_6"].loadFromFile("files/images/number_6.png");
//			textures["number_7"].loadFromFile("files/images/number_7.png");
//			textures["number_8"].loadFromFile("files/images/number_8.png");
//			textures["pause"].loadFromFile("files/images/pause.png");
//			textures["play"].loadFromFile("files/images/play.png");
//			textures["tile_hidden"].loadFromFile("files/images/tile_hidden.png");
//			textures["tile_revealed"].loadFromFile("files/images/tile_revealed.png");
//
//		}
//
//		void RandomTileIds();
//		//void setTileIds(vector<int>& bits, bool oneortwo);
//		void MakeTiles();
//
//		void setBombStates();
//		void setIcons();
//
//		void update(sf::RenderWindow& window);
//		void debug();
//		void draw(sf::RenderWindow& window);
//
//		void refreshCounter();
//		void refreshSmiley();
//
//};