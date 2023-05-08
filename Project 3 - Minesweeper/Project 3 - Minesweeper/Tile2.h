//#pragma once
//#include <SFML/Graphics.hpp>
//#include <string>
//
//using namespace sf;
//using namespace std;
//
//class Tile2 {
//
//private:
//
//	// different tile sprites (icons) in stacked order
//
//	Sprite revealed;
//	Sprite hidden;
//	Sprite flag;
//	Sprite top; // aka mine icon or bordering 1-8 mines icon
//	Sprite paused;
//
//public:
//
//	// different tile bools for functionality
//
//	bool isRevealed;
//	bool isMine;
//	bool isFlag;
//	bool isDebugged;
//	bool isPaused;
//
//	// vector of neighboring tiles
//
//	vector<Tile2*> neighboring = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}; // all 8 neighboring tiles are nullptr by default
//
//	// count of mines tile is bordering
//
//	int minesBordering = 0;
//
//	// default constructor
//
//	Tile2(float x, float y, map<string, Texture>& texturePack) {
//
//		// sets all bools to false by default
//
//		isRevealed = false;
//		isMine = false;
//		isFlag = false;
//		isDebugged = false;
//		isPaused = false;
//
//		// sets sprites to their respective textures
//
//		revealed.setTexture(texturePack["tile_revealed"]);
//		hidden.setTexture(texturePack["tile_hidden"]);
//		flag.setTexture(texturePack["flag"]);
//		paused.setTexture(texturePack["tile_revealed"]);
//		
//		// sets hidden texture as visible, and rest as invisible by default
//
//		revealed.setColor(Color(255, 255, 255, 0));
//		hidden.setColor(Color(255, 255, 255, 255));
//		flag.setColor(Color(255, 255, 255, 0));
//		paused.setColor(Color(255, 255, 255, 0));
//
//		// sets sprites position
//
//		revealed.setPosition(x, y);
//		hidden.setPosition(x, y);
//		flag.setPosition(x, y);
//		paused.setPosition(x, y);
//
//	}
//
//	// various functions
//
//	void updateIcons(map<string, Texture>& texturePack);
//	void drawTiles(RenderWindow& window);
//	bool revealTile(int& tileCounter);
//
//	void flagTile();
//	void debugTile();
//	void pauseTile();
//	void setMine(bool mineStatus);
//
//};
//
//void Tile2::updateIcons(map<string, Texture>& texturePack) {
//
//	minesBordering = 0;
//
//	for (int c = 0; c < 8; c++) { 
//
//		if (neighboring[c] != nullptr && neighboring[c]->isMine == true) { // if neighboring at c is not nullptr and is a mine, minesBordering increases by 1
//
//			minesBordering++;
//
//		}
//
//	}
//
//	if (isMine == true) { // if isMine is equal to true, top's texture is set to mine
//
//		top.setTexture(texturePack["mine"]);
//
//	}
//	else {
//
//		switch (minesBordering) { // else, depending on the value of minesBordering, top's texture is set to the respective texture
//
//		case 1: top.setTexture(texturePack["number_1"]);
//			break;
//
//		case 2: top.setTexture(texturePack["number_2"]);
//			break;
//
//		case 3: top.setTexture(texturePack["number_3"]);
//			break;
//
//		case 4: top.setTexture(texturePack["number_4"]);
//			break;
//
//		case 5: top.setTexture(texturePack["number_5"]);
//			break;
//
//		case 6: top.setTexture(texturePack["number_6"]);
//			break;
//
//		case 7: top.setTexture(texturePack["number_7"]);
//			break;
//
//		case 8: top.setTexture(texturePack["number_8"]);
//			break;
//
//		default: top.setTexture(texturePack["tile_revealed"]);
//			break;
//
//		}
//
//	}
//
//	top.setColor(Color(255, 255, 255, 0));
//	flag.setColor(Color(255, 255, 255, 0));
//	hidden.setColor(Color(255, 255, 255, 255));
//
//	isRevealed = false;
//	isFlag = false;
//	isDebugged = false;
//
//}
//
//void Tile2::drawTiles(RenderWindow& window) { // draws all the icons at their previously set coordinates
//
//	window.draw(revealed);
//	window.draw(hidden);
//	window.draw(flag);
//	window.draw(top);
//	window.draw(paused);
//
//}
//
//bool Tile2::revealTile(int& tileCounter) {
//
//	if (isRevealed == false) { // checks if tile is not already revealed
//
//		isRevealed = true; // sets isRevealed to true which cannot be backed
//		tileCounter++; // increases tileCounter (aka number of tiles revealed) by 1
//
//		hidden.setColor(Color(255, 255, 255, 0)); // makes hidden tile invisible
//		top.setColor(Color(255, 255, 255, 255)); // makes top tile visible
//
//		// checks if minesBordering is equal to 0 and if isMine is false, if so, will recursively reveal surrounding tiles
//
//		if (minesBordering == 0 && isMine == false) { 
//
//			for (int c = 0; c < 8; c++) {
//
//				if (neighboring[c] != nullptr && (neighboring[c]->isMine) == false) {
//
//					neighboring[c]->revealTile(tileCounter);
//
//				}
//			}
//		}
//
//	}
//
//	return isMine;
//
//}
//
//void Tile2::flagTile() {
//
//	if (isRevealed == false) { // checks if tile is not already revealed
//
//		if (isFlag == false) { // if the isFlag bool is false, now set it equal to true and make the flag icon visible
//
//			isFlag = true;
//
//			flag.setColor(Color(255, 255, 255, 255));
//
//		}
//		else if (isFlag == true) { // if the isFlag bool is true, now set it equal to false and make the flag icon invisible
//
//			isFlag = false;
//
//			flag.setColor(Color(255, 255, 255, 0));
//
//		}
//
//	}
//
//}
//
//void Tile2::debugTile() {
//
//	if (isRevealed == false && isMine == true) { // checks if tile is not already revealed and is a mine
//
//		if (isDebugged == false) { // if the isDebugged bool is false, now set it equal to true and make the mine icon visible
//
//			isDebugged = true;
//
//			top.setColor(Color(255, 255, 255, 255));
//
//		}
//		else if (isDebugged == true) { // if the isDebugged bool is true, now set it equal to false and make the mine icon invisible
//
//			isDebugged = false;
//
//			top.setColor(Color(255, 255, 255, 0));
//
//		}
//
//	}
//
//}
//
//void Tile2::pauseTile() {
//
//	if (isPaused == false) { // if the isPaused bool is false, now set it equal to true and make the pause icon visible
//
//		isPaused = true;
//
//		paused.setColor(Color(255, 255, 255, 255));
//
//	}
//	else if (isPaused == true) { // if the isPaused bool is true, now set it equal to false and make the pause icon invisible
//
//		isPaused = false;
//
//		paused.setColor(Color(255, 255, 255, 0));
//
//	}
//
//}
//
//void Tile2::setMine(bool mineStatus) {
//
//	isMine = mineStatus;
//
//}