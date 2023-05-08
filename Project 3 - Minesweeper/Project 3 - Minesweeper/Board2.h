//#pragma once
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <SFML/Graphics.hpp>
//#include <map>
//#include <iostream>
//#include <fstream>
//#include <set>
//#include "Tile2.h"
//
//using namespace sf;
//using namespace std;
//
//class Board2 {
//
//private:
//
//	// int variables for board creation/refreshing
//
//	int width;
//	int height;
//	int mineCount; // total number of mines
//	int windowWidth;
//	int windowHeight;
//
//	int flagsRemaining;
//	int tilesRevealed;
//
//	// bool variables for game completion, ie victory (win) or defeat (loss)
//
//	bool gameOver;
//	bool gameWin;
//	bool gameLoss;
//
//	// map for managing textures
//
//	map<string, Texture> texturePack;
//
//	// vectors for the tiles and tileIDs
//
//	vector<Tile2> boardTiles;
//	vector<bool> boardTileIDs;
//
//	// sprites for bottom interface
//
//	Sprite debugButton;
//	Sprite pauseButton;
//	Sprite leadersButton;
//	Sprite smileyButton;
//
//	Sprite hundreds;
//	Sprite tens;
//	Sprite ones;
//	Sprite negative;
//
//	Sprite secondTens;
//	Sprite secondOnes;
//	Sprite minuteTens;
//	Sprite minuteOnes;
//
//	//Clock timer;
//	//Time elapsed;
//	//Time pausedTime;
//	//Time timeWon;
//
//public:
//
//	// default constructor
//
//	Board2() {
//
//		// reads config file and sets width, height, and mineCount
//
//		ifstream file2("files/board_config.cfg");
//
//		for (int i = 0; i < 3; i++) {
//
//			switch (i) {
//
//			case 0: file2 >> width;
//				break;
//
//			case 1: file2 >> height;
//				break;
//
//			case 2: file2 >> mineCount;
//				break;
//
//			}
//
//		}
//
//		//width = 10;
//		//height = 5;
//		//mineCount = 9;
//
//		// sets textures (put in absolute if statement for increased visibility)
//
//		if (0 == 0) {
//
//			windowWidth = (width * 16);
//			windowHeight = (height * 16 + 100);
//
//			texturePack["debug"].loadFromFile("files/images/debug.png");
//			texturePack["digits"].loadFromFile("files/images/digits.png");
//			texturePack["face_happy"].loadFromFile("files/images/face_happy.png");
//			texturePack["face_lose"].loadFromFile("files/images/face_lose.png");
//			texturePack["face_win"].loadFromFile("files/images/face_win.png");
//			texturePack["flag"].loadFromFile("files/images/flag.png");
//			texturePack["mine"].loadFromFile("files/images/mine.png");
//			texturePack["leaderboard"].loadFromFile("files/images/leaderboard.png");
//			texturePack["number_1"].loadFromFile("files/images/number_1.png");
//			texturePack["number_2"].loadFromFile("files/images/number_2.png");
//			texturePack["number_3"].loadFromFile("files/images/number_3.png");
//			texturePack["number_4"].loadFromFile("files/images/number_4.png");
//			texturePack["number_5"].loadFromFile("files/images/number_5.png");
//			texturePack["number_6"].loadFromFile("files/images/number_6.png");
//			texturePack["number_7"].loadFromFile("files/images/number_7.png");
//			texturePack["number_8"].loadFromFile("files/images/number_8.png");
//			texturePack["pause"].loadFromFile("files/images/pause.png");
//			texturePack["play"].loadFromFile("files/images/play.png");
//			texturePack["tile_hidden"].loadFromFile("files/images/tile_hidden.png");
//			texturePack["tile_revealed"].loadFromFile("files/images/tile_revealed.png");
//
//			debugButton.setTexture(texturePack["debug"]);
//			debugButton.setPosition((width * 32) - 304, 32 * (height + 0.5f));
//
//			pauseButton.setTexture(texturePack["pause"]);
//			pauseButton.setPosition((width * 32) - 240, 32 * (height + 0.5f));
//
//			leadersButton.setTexture(texturePack["leaderboard"]);
//			leadersButton.setPosition((width * 32) - 176, 32 * (height + 0.5f));
//
//			smileyButton.setTexture(texturePack["face_happy"]);
//			smileyButton.setPosition(((width / 2.0) * 32) - 32, 32 * (height + 0.5f));
//
//			hundreds.setTexture(texturePack["digits"]);
//			hundreds.setTextureRect(Rect<int>(0, 0, 21, 32));
//			hundreds.setPosition(33, 32 * (height + 0.5f) + 16);
//
//			tens.setTexture(texturePack["digits"]);
//			tens.setTextureRect(Rect<int>(0, 0, 21, 32));
//			tens.setPosition(54, 32 * (height + 0.5f) + 16);
//
//			ones.setTexture(texturePack["digits"]);
//			ones.setTextureRect(Rect<int>(0, 0, 21, 32));
//			ones.setPosition(75, 32 * (height + 0.5f) + 16);
//
//			negative.setTexture(texturePack["digits"]);
//			negative.setPosition(12, 32 * (height + 0.5f) + 16);
//			negative.setColor(Color(255, 255, 255, 0));
//
//			int x = ((width * 32) - 54);
//			int y = (32 * (height + 0.5f) + 16);
//
//			secondTens.setTexture(texturePack["digits"]);
//			secondTens.setPosition(x, y);
//			x += 21;
//			secondOnes.setTexture(texturePack["digits"]);
//			secondOnes.setPosition(x, y);
//
//			x = ((width * 32) - 97);
//			minuteTens.setTexture(texturePack["digits"]);
//			minuteTens.setPosition(x, y);
//			x += 21;
//			minuteOnes.setTexture(texturePack["digits"]);
//			minuteOnes.setPosition(x, y);
//
//		}
//
//		makeTiles();
//		setRandomTiles();
//
//	}
//
//	// functions
//
//	void makeTiles(); // sets the tiles
//	void updateBoard(RenderWindow& gameWindow); // updates the board after any player interaction
//	void drawBoard(RenderWindow& gameWindow); // draws the current board
//	void setRandomTiles(); // generates a list of unique random numbers that will be the locations of the mines
//	void setMines(); // sets the mines on the board using the numbers generated by setRandomTiles
//	void setTextures(); // sets the textures for the tiles
//
//};
//
//void Board2::makeTiles() {
//
//	float tempX = 0;
//	float tempY = 0;
//
//	// imbedded loop generates the tiles using tempX and tempY which adjust by 32.0f as needed for each tile
//
//	for (int i = 0; i < height; i++) {
//
//		for (int n = 0; n < width; n++) {
//
//			Tile2 tileT = Tile2(tempX, tempY, texturePack);
//
//			boardTiles.push_back(tileT);
//
//			tempX = tempX + 32.0f;
//
//		}
//
//		tempX = 0;
//		tempY = tempY + 32.0f;
//
//	}
//
//}
//
//void Board2::updateBoard(RenderWindow& gameWindow) {
//
//	drawBoard(gameWindow);
//
//	// left click functionality
//
//	if (Mouse::isButtonPressed(Mouse::Left)) {
//
//		Vector2i mousePosition = Mouse::getPosition(gameWindow);
//
//		// clicking on the game board
//
//		if (mousePosition.y >= 0 && mousePosition.y < (height * 32) && (gameOver == false)) {
//
//			int tileClicked = (((mousePosition.y / 32) * width) + (mousePosition.x / 32));
//			int count = 0;
//
//			if (boardTiles[tileClicked].revealTile(count)) {
//
//				gameOver = true;
//				gameLoss = true;
//				gameWin = false;
//
//				int zero = 0;
//
//				for (int c = 0; c < (width * height); c++) {
//
//					if (boardTiles[c].isFlag && boardTiles[c].isMine) {
//
//						boardTiles[c].flagTile();
//
//					}
//
//					if (boardTiles[c].isMine) {
//
//						boardTiles[c].revealTile(zero);
//
//					}
//
//				}
//
//			}
//			else {
//
//				tilesRevealed = tilesRevealed + count;
//
//			}
//
//		}
//
//		// clicking on the bottom interface
//
//	}
//
//	drawBoard(gameWindow);
//
//}
//
//void Board2::drawBoard(RenderWindow& gameWindow) {
//
//	// loop draws every tile's sprites
//
//	for (int i = 0; i < (width * height); i++) {
//
//		boardTiles[i].drawTiles(gameWindow);
//
//	}
//
//	// draws game window's sprites
//
//	gameWindow.draw(debugButton);
//	gameWindow.draw(pauseButton);
//	gameWindow.draw(leadersButton);
//	gameWindow.draw(smileyButton);
//
//	gameWindow.draw(hundreds);
//	gameWindow.draw(tens);
//	gameWindow.draw(ones);
//	gameWindow.draw(negative);
//
//	gameWindow.draw(secondTens);
//	gameWindow.draw(secondOnes);
//	gameWindow.draw(minuteTens);
//	gameWindow.draw(minuteOnes);
//
//}
//
//void Board2::setRandomTiles() {
//
//	boardTileIDs.clear();
//
//	map<int, int> mineLocations;
//	set<int> mineSet;
//
//	// by default sets every tile as not a mine
//
//	for (int i = 0; i < (width * height); i++) {
//
//		boardTileIDs.push_back(false);
//
//	}
//
//	// while loop generates a list of unique numbers between 0 and total tiles by utilizing a set, mineSet
//
//	while (mineSet.size() < mineCount) {
//
//		mineSet.emplace(rand() % (width * height));
//
//	}
//
//	// sets the mine locations in mineLocations and boardTileIDs
//
//	for (set<int>::iterator itr = mineSet.begin(); itr != mineSet.end(); itr++) {
//
//		mineLocations[*itr] = (*itr);
//		boardTileIDs[(*itr)] = (*itr);
//
//	}
//
//	cout << "Total Tiles:: " << boardTileIDs.size() << endl;
//	cout << "Total Mines: " << mineSet.size() << endl;
//
//	setMines();
//	setTextures();
//
//}
//
//void Board2::setMines() {
//
//	for (int i = 0; i < (width * height); i++) {
//
//		// i is where the tile (and mine) is and boardTileIDs[i] is the tile's mine status (1 means mine, 0 means not a mine)
//
//		boardTiles[i].setMine(boardTileIDs[i]);
//
//	}
//
//}
//
//void Board2::setTextures() {
//
//	for (int i = 0; i < (width * height); i++) {
//
//		if (i == 0) { // top left corner tile
//
//			boardTiles[i].neighboring[4] = &(boardTiles[i + 1]);
//			boardTiles[i].neighboring[6] = &(boardTiles[i + width]);
//			boardTiles[i].neighboring[7] = &(boardTiles[i + (width + 1)]);
//
//		}
//		else if (i == (width - 1)) { // top right corner tile
//
//			boardTiles[i].neighboring[3] = &(boardTiles[i - 1]);
//			boardTiles[i].neighboring[5] = &(boardTiles[i + (width - 1)]);
//			boardTiles[i].neighboring[6] = &(boardTiles[i + width]);
//
//		}
//		else if (i == ((width * height) - (width))) { // bottom left corner tile
//
//			boardTiles[i].neighboring[4] = &(boardTiles[i + 1]);
//			boardTiles[i].neighboring[1] = &(boardTiles[i - width]);
//			boardTiles[i].neighboring[2] = &(boardTiles[i - (width - 1)]);
//
//		}
//		else if (i == ((width * height) - 1)) { // bottom right corner
//
//			boardTiles[i].neighboring[3] = &(boardTiles[i - 1]);
//			boardTiles[i].neighboring[1] = &(boardTiles[i - width]);
//			boardTiles[i].neighboring[0] = &(boardTiles[i - (width + 1)]);
//
//		}
//		else if (i < (width - 1)) { // top side tiles
//
//			boardTiles[i].neighboring[3] = &(boardTiles[i - 1]);
//			boardTiles[i].neighboring[4] = &(boardTiles[i + 1]);
//			boardTiles[i].neighboring[5] = &(boardTiles[i + (width - 1)]);
//			boardTiles[i].neighboring[6] = &(boardTiles[i + (width)]);
//			boardTiles[i].neighboring[7] = &(boardTiles[i + (width + 1)]);
//
//		}
//		else if (i > ((width * height) - (width))) { // bottom side tiles
//
//			boardTiles[i].neighboring[3] = &(boardTiles[i - 1]);
//			boardTiles[i].neighboring[4] = &(boardTiles[i + 1]);
//			boardTiles[i].neighboring[2] = &(boardTiles[i - (width - 1)]);
//			boardTiles[i].neighboring[1] = &(boardTiles[i - width]);
//			boardTiles[i].neighboring[0] = &(boardTiles[i - (width + 26)]);
//
//		}
//		else if ((i % width) == 0) { // left side tiles
//
//			boardTiles[i].neighboring[4] = &(boardTiles[i + 1]);
//			boardTiles[i].neighboring[6] = &(boardTiles[i + width]);
//			boardTiles[i].neighboring[7] = &(boardTiles[i + (width + 1)]);
//			boardTiles[i].neighboring[1] = &(boardTiles[i - width]);
//			boardTiles[i].neighboring[2] = &(boardTiles[i - (width - 1)]);
//
//		}
//		else if (((i - 24) % 25) == 0) { // rigth side tiles
//
//			boardTiles[i].neighboring[3] = &(boardTiles[i - 1]);
//			boardTiles[i].neighboring[0] = &(boardTiles[i - (width + 1)]);
//			boardTiles[i].neighboring[1] = &(boardTiles[i - width]);
//			boardTiles[i].neighboring[5] = &(boardTiles[i + (width - 1)]);
//			boardTiles[i].neighboring[6] = &(boardTiles[i + width]);
//
//		}
//		else { // middle tiles
//
//			boardTiles[i].neighboring[3] = &(boardTiles[i - 1]);
//			boardTiles[i].neighboring[0] = &(boardTiles[i - (width + 1)]);
//			boardTiles[i].neighboring[1] = &(boardTiles[i - width]);
//			boardTiles[i].neighboring[5] = &(boardTiles[i + (width - 1)]);
//			boardTiles[i].neighboring[6] = &(boardTiles[i + width]);
//			boardTiles[i].neighboring[4] = &(boardTiles[i + 1]);
//			boardTiles[i].neighboring[7] = &(boardTiles[i + (width + 1)]);
//			boardTiles[i].neighboring[2] = &(boardTiles[i - (width - 1)]);
//
//		}
//
//		boardTiles[i].updateIcons(texturePack);
//
//	}
//
//} 
