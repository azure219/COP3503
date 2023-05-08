//#pragma once
//#include "Tile.h"
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <SFML/Graphics.hpp>
//#include <algorithm>
//#include <map>
//#include <iostream>
//#include <fstream>
//#include <set>
//using namespace std;
//using namespace sf;
//
//class Controller
//{
//	int flagsavailable;
//	int numbombs;
//	int tilesrevealed;
//
//	map<string, Texture> icontextures;
//	vector<bool> tileids;
//	vector<int> testcase1;
//	vector<int> testcase2;
//
//	Sprite debugicon;
//	Sprite test1;
//	Sprite test2;
//	Sprite smiley;
//
//	Sprite hundreds;
//	Sprite tens;
//	Sprite ones;
//	Sprite negative;
//
//	bool islost;
//	bool isover;
//
//public:
//	vector<Tile> tiles;
//
//	Controller();
//
//	void RandomTileIds();
//	void setTileIds(vector<int>& bits, bool oneortwo);
//	void MakeTiles();
//
//	void setBombStates();
//	void setIcons();
//
//	void update(RenderWindow& window);
//	void debug();
//	void draw(RenderWindow& window);
//
//	void refreshCounter();
//	void refreshSmiley();
//};
//
////sets flagsavailable to 50, reads all the textures, calls maketiles, randomtileids
//Controller::Controller()
//{
//	srand(time(NULL));
//	flagsavailable = numbombs;
//
//	fstream file;
//	string lineholder;
//	file.open("boards/testboard.brd");
//	if (file.is_open())
//	{
//		while (getline(file, lineholder))
//		{
//			auto iter = lineholder.begin();
//			while (iter != lineholder.end())
//			{
//				int holder = (*iter) - 48;
//				testcase1.push_back(holder);
//				iter++;
//			}
//		}
//	}
//	file.close();
//
//	file.open("boards/testboard2.brd");
//	if (file.is_open())
//	{
//		while (getline(file, lineholder))
//		{
//			auto iter = lineholder.begin();
//			while (iter != lineholder.end())
//			{
//				int holder = (*iter) - 48;
//				testcase2.push_back(holder);
//				iter++;
//			}
//		}
//	}
//	file.close();
//
//	Texture holder;
//	holder.loadFromFile("files/images/debug.png"); //console buttons
//	icontextures.emplace("debug", holder);
//	holder.loadFromFile("files/images/pause.png");
//	icontextures.emplace("testone", holder);
//	holder.loadFromFile("files/images/leaderboard.png");
//	icontextures.emplace("testtwo", holder);
//
//	holder.loadFromFile("files/images/digits.png"); //digits
//	icontextures.emplace("digits", holder);
//
//	holder.loadFromFile("files/images/face_happy.png"); //face button
//	icontextures.emplace("happy", holder);
//	holder.loadFromFile("files/images/face_lose.png");
//	icontextures.emplace("lose", holder);
//	holder.loadFromFile("files/images/face_win.png");
//	icontextures.emplace("win", holder);
//
//	holder.loadFromFile("files/images/flag.png"); //tile icons
//	icontextures.emplace("flag", holder);
//	holder.loadFromFile("files/images/mine.png");
//	icontextures.emplace("bomb", holder);
//	holder.loadFromFile("files/images/number_1.png");
//	icontextures.emplace("one", holder);
//	holder.loadFromFile("files/images/number_2.png");
//	icontextures.emplace("two", holder);
//	holder.loadFromFile("files/images/number_3.png");
//	icontextures.emplace("three", holder);
//	holder.loadFromFile("files/images/number_4.png");
//	icontextures.emplace("four", holder);
//	holder.loadFromFile("files/images/number_5.png");
//	icontextures.emplace("five", holder);
//	holder.loadFromFile("files/images/number_6.png");
//	icontextures.emplace("six", holder);
//	holder.loadFromFile("files/images/number_7.png");
//	icontextures.emplace("seven", holder);
//	holder.loadFromFile("files/images/number_8.png");
//	icontextures.emplace("eight", holder);
//
//	holder.loadFromFile("files/images/tile_hidden.png"); //tile states
//	icontextures.emplace("hidden", holder);
//	holder.loadFromFile("files/images/tile_revealed.png");
//	icontextures.emplace("revealed", holder);
//
//	debugicon.setTexture(icontextures["debug"]);
//	debugicon.setPosition(496, 512);
//	test1.setTexture(icontextures["testone"]);
//	test1.setPosition(560, 512);
//	test2.setTexture(icontextures["testtwo"]);
//	test2.setPosition(624, 512);
//	smiley.setTexture(icontextures["happy"]);
//	smiley.setPosition(368, 512);
//
//	hundreds.setTexture(icontextures["digits"]);
//	hundreds.setTextureRect(Rect<int>(0, 0, 21, 32));
//	hundreds.setPosition(0, 512);
//	tens.setTexture(icontextures["digits"]);
//	tens.setTextureRect(Rect<int>(21 * 5, 0, 21, 32));
//	tens.setPosition(21, 512);
//	ones.setTexture(icontextures["digits"]);
//	ones.setTextureRect(Rect<int>(0, 0, 21, 32));
//	ones.setPosition(42, 512);
//
//	MakeTiles();
//	RandomTileIds();
//}
//
//// creates a vector of 50 random numbers between 0 and 399, with no duplicates
////then uses that vector to create a vector of 400 bools, 50 of which will be true, and assign to tileids
////then calls seticons and setbombstates
//void Controller::RandomTileIds()
//{
//
//	tileids.clear();
//
//	map<int, int> mineLocations;
//	set<int> mineSet;
//
//	for (int i = 0; i < (25 * 16); i++) {
//
//		tileids.push_back(false);
//
//	}
//
//	while (mineSet.size() < numbombs) {
//
//		mineSet.emplace(rand() % (25 * 16));
//
//	}
//
//	for (set<int>::iterator itr = mineSet.begin(); itr != mineSet.end(); itr++) {
//
//		mineLocations[*itr] = *itr;
//		tileids[(*itr)] = (*itr);
//	
//	}
//
//	cout << "tileids size: " << tileids.size() << endl;
//
//	setBombStates();
//	setIcons();
//	flagsavailable = numbombs;
//	refreshCounter();
//	tilesrevealed = 0;
//
//	islost = false;
//	isover = false;
//}
//
////takes in an array of 400 1s and 0s, and converts them to bools to set tileids
////then calls seticons and setbombstates
//void Controller::setTileIds(vector<int>& bits, bool oneortwo)
//{
//	tileids.clear();
//	for (int c = 0; c < 400; c++)
//	{
//		if (bits[c] == 0)
//		{
//			tileids.push_back(false);
//		}
//		else
//		{
//			tileids.push_back(true);
//		}
//	}
//	setBombStates();
//	setIcons();
//	refreshCounter();
//	if (oneortwo)
//		numbombs = 1;
//	else numbombs = 98;
//
//	flagsavailable = numbombs;
//	refreshCounter();
//
//	islost = false;
//	isover = false;
//}
//
////instantiates the array of tiles, which will remain static over all games played during this instance
//void Controller::MakeTiles()
//{
//	float x = 0; float y = 0;
//	for (int c = 0; c < 16; c++)
//	{
//		for (int d = 0; d < 25; d++)
//		{
//			Tile t = Tile(icontextures, x, y);
//			tiles.push_back(t);
//			x += 32.f;
//		}
//		x = 0;
//		y += 32.f;
//	}
//}
//
////calls setbombstate on each tile in tiles
////for use ONLY when the game is reset, otherwise you'll just make a big mess
//void Controller::setBombStates()
//{
//	for (int c = 0; c < 400; c++)
//	{
//		tiles[c].setBombState(tileids[c]);
//	}
//}
//
////assigns icons to each tile based on isbomb and nearby bombs
//void Controller::setIcons()
//{
//	for (int c = 0; c < 400; c++)
//	{
//		tiles[c].neighbors.clear();
//		for (int d = 0; d < 8; d++)
//		{
//			tiles[c].neighbors.push_back(nullptr);
//		}
//		if (c == 0) //tile is top left corner
//		{
//			tiles[c].neighbors[4] = &(tiles[c + 1]);
//			tiles[c].neighbors[6] = &(tiles[c + 25]);
//			tiles[c].neighbors[7] = &(tiles[c + 26]);
//		}
//		else if (c == 24) // tile is top right corner
//		{
//			tiles[c].neighbors[3] = &(tiles[c - 1]);
//			tiles[c].neighbors[5] = &(tiles[c + 24]);
//			tiles[c].neighbors[6] = &(tiles[c + 25]);
//		}
//		else if (c == 375) // tile is bottom left corner
//		{
//			tiles[c].neighbors[4] = &(tiles[c + 1]);
//			tiles[c].neighbors[1] = &(tiles[c - 25]);
//			tiles[c].neighbors[2] = &(tiles[c - 24]);
//		}
//		else if (c == 399) // tile is bottom right corner
//		{
//			tiles[c].neighbors[3] = &(tiles[c - 1]);
//			tiles[c].neighbors[1] = &(tiles[c - 25]);
//			tiles[c].neighbors[0] = &(tiles[c - 26]);
//		}
//		else if (c < 24) // tile is on the top
//		{
//			tiles[c].neighbors[3] = &(tiles[c - 1]);
//			tiles[c].neighbors[4] = &(tiles[c + 1]);
//			tiles[c].neighbors[5] = &(tiles[c + 24]);
//			tiles[c].neighbors[6] = &(tiles[c + 25]);
//			tiles[c].neighbors[7] = &(tiles[c + 26]);
//		}
//		else if (c > 375) // tile is on the bottom
//		{
//			tiles[c].neighbors[3] = &(tiles[c - 1]);
//			tiles[c].neighbors[4] = &(tiles[c + 1]);
//			tiles[c].neighbors[2] = &(tiles[c - 24]);
//			tiles[c].neighbors[1] = &(tiles[c - 25]);
//			tiles[c].neighbors[0] = &(tiles[c - 26]);
//		}
//		else if ((c % 25) == 0) // tile is on the right edge
//		{
//			tiles[c].neighbors[4] = &(tiles[c + 1]);
//			tiles[c].neighbors[6] = &(tiles[c + 25]);
//			tiles[c].neighbors[7] = &(tiles[c + 26]);
//			tiles[c].neighbors[1] = &(tiles[c - 25]);
//			tiles[c].neighbors[2] = &(tiles[c - 24]);
//		}
//		else if (((c - 24) % 25) == 0) // tile is on the left edge
//		{
//			tiles[c].neighbors[3] = &(tiles[c - 1]);
//			tiles[c].neighbors[0] = &(tiles[c - 26]);
//			tiles[c].neighbors[1] = &(tiles[c - 25]);
//			tiles[c].neighbors[5] = &(tiles[c + 24]);
//			tiles[c].neighbors[6] = &(tiles[c + 25]);
//		}
//		else // tile is in the middle
//		{
//			tiles[c].neighbors[3] = &(tiles[c - 1]);
//			tiles[c].neighbors[4] = &(tiles[c + 1]);
//			tiles[c].neighbors[5] = &(tiles[c + 24]);
//			tiles[c].neighbors[6] = &(tiles[c + 25]);
//			tiles[c].neighbors[7] = &(tiles[c + 26]);
//			tiles[c].neighbors[2] = &(tiles[c - 24]);
//			tiles[c].neighbors[1] = &(tiles[c - 25]);
//			tiles[c].neighbors[0] = &(tiles[c - 26]);
//		}
//		tiles[c].updateIcon(icontextures);
//	}
//}
//
////checks for left and right clicks
//void Controller::update(RenderWindow& window)
//{
//	if (Mouse::isButtonPressed(Mouse::Left))
//	{
//
//		Vector2i position = Mouse::getPosition(window);
//		if (position.y >= 0 && position.y < 512 && !isover)
//		{
//			if (position.x >= 0 && position.x <= 800)
//			{
//				int x = (position.x / 32);
//				int y = (position.y / 32);
//
//				int pos = (y * 25) + x;
//				int count = 0;
//				if (tiles[pos].reveal(count))
//				{
//					islost = true;
//					isover = true;
//					int dummycount = 0;
//					for (int c = 0; c < 400; c++)
//					{
//						if (tiles[c].isflagged && tiles[c].isbomb)
//							tiles[c].toggleFlag();
//						if (tiles[c].isbomb )
//							tiles[c].reveal(dummycount);
//					}
//				}
//				else tilesrevealed += count;
//			}
//		}
//		else if (position.y >= 512 && position.y < 572)
//		{
//			if (position.x >= 368 && position.x < 432)
//			{
//				RandomTileIds();
//			}
//			if (position.x >= 496 && position.x < 560 && !isover)
//			{
//				debug();
//			}
//			if (position.x >= 560 && position.x < 624 && !isover)
//			{
//				//setTileIds(testcase1, true);
//			}
//			if (position.x >= 624 && position.x < 688 && !isover)
//			{
//				//setTileIds(testcase2, false);
//			}
//		}
//	}
//
//	if (Mouse::isButtonPressed(Mouse::Right) && !isover)
//	{
//		Vector2i position = Mouse::getPosition(window);
//		if (position.x >= 0 && position.x <= 800)
//		{
//			if (position.y >= 0 && position.y <= 512)
//			{
//				int x = (position.x / 32);
//				int y = (position.y / 32);
//
//				int pos = (y * 25) + x;
//				if (!tiles[pos].isflagged && flagsavailable > 0 && !tiles[pos].isrevealed)
//				{
//					tiles[pos].toggleFlag();
//					flagsavailable--;
//				}
//				else if (!tiles[pos].isrevealed && tiles[pos].isflagged)
//				{
//					tiles[pos].toggleFlag();
//					flagsavailable++;
//				}
//				refreshCounter();
//			}
//		}
//	}
//
//	if (tilesrevealed == (400 - numbombs) && !islost)
//	{
//		isover = true;
//		for (int e = 0; e < 400; e++)
//		{
//			if (tiles[e].isbomb && !tiles[e].isflagged)
//			{
//				tiles[e].toggleFlag();
//			}
//		}
//	}
//
//	refreshSmiley();
//
//	draw(window);
//}
//
////calls toggleDebug on each tile
//void Controller::debug()
//{
//	for (int c = 0; c < 400; c++)
//	{
//		tiles[c].toggleDebug();
//	}
//}
//
////calls draw on each tile in tiles
//void Controller::draw(RenderWindow& window)
//{
//	for (int c = 0; c < 400; c++)
//		tiles[c].draw(window);
//
//	window.draw(smiley);
//	window.draw(debugicon);
//	window.draw(test1);
//	window.draw(test2);
//
//	window.draw(hundreds);
//	window.draw(tens);
//	window.draw(ones);
//}
//
//void Controller::refreshCounter()
//{
//	int copy = flagsavailable;
//	int onesplace = copy % 10;
//	copy /= 10;
//	int tensplace = copy % 10;
//
//	tens.setTextureRect(Rect<int>(21 * tensplace, 0, 21, 32));
//	ones.setTextureRect(Rect<int>(21 * onesplace, 0, 21, 32));
//}
//
//void Controller::refreshSmiley()
//{
//	if (isover)
//	{
//		if (islost)
//			smiley.setTexture(icontextures["lose"]);
//		else
//			smiley.setTexture(icontextures["win"]);
//	}
//	else smiley.setTexture(icontextures["happy"]);
//}