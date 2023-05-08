//#include <iostream>
//#include <iomanip>
//#include <random>
//#include <vector>
//#include <SFML/Graphics.hpp>
//#include <fstream>
//#include <cctype>
//#include "gameWindow.h"
//#include "tiles.h"
//using namespace std;
//
//void gameWindow::RandomTileIds() {
//
//	tileMineID.clear();
//
//	vector<int> mineLocations;
//	bool isDuplicate = false;
//
//	for (int i = 1; i <= mines; i++) {
//
//		int random = 1 + (rand() % (width * height));
//
//		for (int n = 0; n < mineLocations.size(); n++) {
//
//			if (random == mineLocations.at(n)) {
//
//				isDuplicate = true;
//				i--;
//				break;
//
//			}
//
//		}
//
//		if (isDuplicate == false) {
//
//			mineLocations.push_back(random);
//		
//		}
//
//	}
//
//	for (int i = 1; i <= (width * height); i++) {
//
//		for (int n = 0; n < mineLocations.size(); n++) {
//
//			if (i == mineLocations.at(n)) {
//
//				tileMineID[i] = true;
//
//			}
//
//		}
//
//		tileMineID[i] = false;
//
//	}
//
//	setBombStates();
//	setIcons();
//	flagsLeft = 50;
//	refreshCounter();
//	minesLeft = 50;
//	tilesRevealed = 0;
//
//	isLost = false;
//	isOver = false;
//
//}
//
////void gameWindow::setTileIds(vector<int>& bits, bool oneortwo) {
////
////}
//
//void gameWindow::MakeTiles() {
//
//	float x, y = 0.0;
//
//	for (int i = 0; i < height; i++) {
//
//		for (int n = 0; n < width; n++) {
//
//			tile tempTile = tile(textures, x, y);
//			tilesVector.push_back(tempTile);
//
//			x = x + 32.0;
//
//		}
//
//		x = 0.0;
//		y = y + 32.0;
//
//	}
//
//}
//
//void gameWindow::setBombStates() {
//
//	for (int i = 1; i <= (height * width); i++) {
//
//		tilesVector[i].createMine(tileMineID.at(i));
//
//	}
//
//}
//
//void gameWindow::setIcons() {
//
//	for (int i = 1; i <= (height * width); i++) { // i is 1-400, not 0-399
//
//		tilesVector[(i)].neighboring.clear();
//
//		for (int n = 0; n < 8; n++) {
//
//			tilesVector[(i)].neighboring.push_back(nullptr);
//
//		}
//
//		if (i == 1) { // top left corner
//
//			tilesVector[(i)].neighboring[4] = &(tilesVector[i + 1]);
//			tilesVector[(i)].neighboring[6] = &(tilesVector[i + width]);
//			tilesVector[(i)].neighboring[7] = &(tilesVector[i + (width + 1)]);
//
//		}
//		else if (i == width) { // top right corner
//
//			tilesVector[(i)].neighboring[3] = &(tilesVector[width - 1]);
//			tilesVector[(i)].neighboring[5] = &(tilesVector[i + (width - 1)]);
//			tilesVector[(i)].neighboring[6] = &(tilesVector[i + width]);
//
//		}
//		else if (i == ((height * width) - width)) { // bottom left corner
//
//			tilesVector[(i)].neighboring[1] = &(tilesVector[i - width]);
//			tilesVector[(i)].neighboring[2] = &(tilesVector[i - (width + 1)]);
//			tilesVector[(i)].neighboring[4] = &(tilesVector[i + 1]);
//
//		}
//		else if (i == (height * width)) { // bottom right corner
//
//			tilesVector[(i)].neighboring[0] = &(tilesVector[i - (width - 1)]);
//			tilesVector[(i)].neighboring[1] = &(tilesVector[i - width]);
//			tilesVector[(i)].neighboring[3] = &(tilesVector[i - 1]);
//
//		}
//		else if (i < width) { // on top
//
//			tilesVector[(i)].neighboring[3] = &(tilesVector[i - 1]);
//			tilesVector[(i)].neighboring[4] = &(tilesVector[i + 1]);
//			tilesVector[(i)].neighboring[5] = &(tilesVector[i + (width - 1)]);
//			tilesVector[(i)].neighboring[6] = &(tilesVector[i + width]);
//			tilesVector[(i)].neighboring[7] = &(tilesVector[i + (width + 1)]);
//
//		}
//		else if (i > ((height * width) - width)) { // on bottom
//
//			tilesVector[(i)].neighboring[0] = &(tilesVector[i - (width + 1)]);
//			tilesVector[(i)].neighboring[1] = &(tilesVector[i - width]);
//			tilesVector[(i)].neighboring[2] = &(tilesVector[i - (width - 1)]);
//			tilesVector[(i)].neighboring[3] = &(tilesVector[i - 1]);
//			tilesVector[(i)].neighboring[4] = &(tilesVector[i + 1]);
//
//		}
//		else if ((i % width) == 0) { // on right side
//
//			tilesVector[(i)].neighboring[0] = &(tilesVector[i - (width + 1)]);
//			tilesVector[(i)].neighboring[1] = &(tilesVector[i - width]);
//			tilesVector[(i)].neighboring[3] = &(tilesVector[i - 1]);
//			tilesVector[(i)].neighboring[5] = &(tilesVector[i + (width - 1)]);
//			tilesVector[(i)].neighboring[6] = &(tilesVector[i + width]);
//
//		}
//		else if (i % width == 1) { // on left side
//
//			tilesVector[(i)].neighboring[1] = &(tilesVector[i - width]);
//			tilesVector[(i)].neighboring[2] = &(tilesVector[i - (width - 1)]);
//			tilesVector[(i)].neighboring[4] = &(tilesVector[i + 1]);
//			tilesVector[(i)].neighboring[6] = &(tilesVector[i + width]);
//			tilesVector[(i)].neighboring[7] = &(tilesVector[i + width + 1]);
//
//		}
//		else { // in middle
//
//			tilesVector[(i)].neighboring[0] = &(tilesVector[i - (width + 1)]);
//			tilesVector[(i)].neighboring[1] = &(tilesVector[i - width]);
//			tilesVector[(i)].neighboring[2] = &(tilesVector[i - (width - 1)]);
//			tilesVector[(i)].neighboring[3] = &(tilesVector[i - 1]);
//			tilesVector[(i)].neighboring[4] = &(tilesVector[i + 1]);
//			tilesVector[(i)].neighboring[5] = &(tilesVector[i + (width - 1)]);
//			tilesVector[(i)].neighboring[6] = &(tilesVector[i + width]);
//			tilesVector[(i)].neighboring[7] = &(tilesVector[i + width + 1]);
//
//		}
//
//		tilesVector[(i)].updateIcon(textures);
//
//	}
//
//}
//
//void gameWindow::update(sf::RenderWindow& window) {
//
//
//
//}
//
//void gameWindow::debug() {
//
//	for (int c = 1; c <= 400; c++) {
//
//		tilesVector[c].Debug();
//
//	}
//
//}
//
//void gameWindow::draw(sf::RenderWindow& window) {
//
//	for (int c = 1; c <= 400; c++) {
//
//		tilesVector[c].Create(window);
//
//	}
//
//	window.draw(reset);
//	window.draw(debugger);
//
//}
//
//void gameWindow::refreshCounter() {
//
//
//
//}
//
//void gameWindow::refreshSmiley() {
//
//	if (isOver == true)
//	{
//		if (isLost) {
//
//			reset.setTexture(textures["face_lose"]);
//
//		}
//		else {
//
//			reset.setTexture(textures["face_win"]);
//
//		}
//	}
//	else {
//
//		reset.setTexture(textures["face_happy"]);
//
//	}
//}
//
//
////void gameWindow::createBoard(int height_, int width_) {
//// 
////	height = height_;
////	width = width_;
////
////	for (unsigned int h = 0; h < height; h++) {
////
////		for (unsigned int w = 0; w < width; w++) {
////
////			sf::Vector2f position = sf::Vector2f((float)(w) * 32, (float)(h) * 32);
////			tile tempTile = tile(position, "tile_hidden", 0);
////			tileboard.push_back(tempTile);
////
////		}
////
////	}
////
////	int counter = 0;
////
////	for (unsigned int h = 0; h < height; h++) {
////
////		for (unsigned int w = 0; w < width; w++) {
////
////			sf::FloatRect mineRect = tileboard.at(counter).returnSprite().getLocalBounds();
////			tileboard.at(counter).returnSprite().setOrigin((float)(w) * 32, (float)(h) * 32);
////			tileboard.at(counter).returnSprite().setPosition(sf::Vector2f((float)(w) * 32, (float)(h) * 32));
////
////			counter++;
////
////		}
////
////	}
////
////}
////
////void gameWindow::runGW() {
////
////	cout << "OPENING GAME WINDOW...";
////
////	ifstream file("files/board_config.cfg");
////
////	for (int i = 0; i < 3; i++) {
////
////		file >> dimensions[i];
////		//out << dimensions[i] << " ";
////
////	}
////
////	int h = (dimensions[1] * 32 + 100);
////	int w = (dimensions[0] * 32);
////
////	sf::RenderWindow gWindow(sf::VideoMode(w, h), "MINESWEEPER!");
////
////	gameWindow gw = gameWindow();
////	//gw.createBoard(h, w);
////
////}