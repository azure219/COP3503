#pragma onceinclude <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Tile {

	private:

		// different sprites
		Sprite background;
		Sprite foreground;
		Sprite topIcon;
		Sprite flagIcon;

	public:

		// public variables
		int mines;
		bool isMine;
		bool isFlag;
		bool isRevealed;
		bool isDebug;

		Sprite pauseIcon;

		// default constructor
		Tile(map<string, Texture>& textures, float xpos, float ypos);

		// vector to record neighboring tiles
		vector<Tile*> neighboring;
	
		// Tile functions (what any Tile might have to do)
		void setMineStatus(bool bombstate);
		void updateIcon(map<string, Texture>& textures);
		bool Flag();
		void Debug();
		bool Reveal(int& counter);
		void drawWindow(RenderWindow& w);
		void createPauseScreen(bool isPaused);
		bool flagStatus();

};

// default constructor (sets textures, positions, bools, and transparency)
Tile::Tile(map<string, Texture>& textures, float x, float y) {

	background.setTexture(textures["tile_revealed"]);
	foreground.setTexture(textures["tile_hidden"]);
	flagIcon.setTexture(textures["flag"]);
	pauseIcon.setTexture(textures["tile_revealed"]);

	background.setPosition(x, y);
	foreground.setPosition(x, y);
	flagIcon.setPosition(x, y);
	topIcon.setPosition(x, y);
	pauseIcon.setPosition(x, y);

	isMine = false;
	isRevealed = false;
	isFlag = false;
	isDebug = false;

	pauseIcon.setColor(Color(255, 255, 255, 0));

}

void Tile::setMineStatus(bool bombstate) {
	
	isMine = bombstate;

}

void Tile::updateIcon(map<string, Texture>& textures) {

	mines = 0;

	for (int c = 0; c < 8; c++) {

		if (neighboring[c] != nullptr && neighboring[c]->isMine) {

			mines++;

		}
	
	}

	if (isMine) {

		topIcon.setTexture(textures["mine"]);

	}
	else {

		switch (mines) {

			case 1: topIcon.setTexture(textures["number_1"]); 
				break;

			case 2: topIcon.setTexture(textures["number_2"]); 
				break;
		
			case 3: topIcon.setTexture(textures["number_3"]); 
				break;
		
			case 4: topIcon.setTexture(textures["number_4"]); 
				break;
		
			case 5: topIcon.setTexture(textures["number_5"]); 
				break;
		
			case 6: topIcon.setTexture(textures["number_6"]); 
				break;
		
			case 7: topIcon.setTexture(textures["number_7"]); 
				break;
		
			case 8: topIcon.setTexture(textures["number_8"]); 
				break;
		
			default: topIcon.setTexture(textures["tile_revealed"]); 
				break;

		}

	}

	topIcon.setColor(Color(255, 255, 255, 0));

	flagIcon.setColor(Color(255, 255, 255, 0));
	foreground.setColor(Color(255, 255, 255, 255));

	isRevealed = false;
	isFlag = false;
	isDebug = false;

}

bool Tile::Flag() {

	if (!isRevealed) {

		if (isFlag) {

			isFlag = false;
			flagIcon.setColor(Color(255, 255, 255, 0));

		}
		else {

			isFlag = true;
			flagIcon.setColor(Color(255, 255, 255, 255));

		}

	}

	return isFlag;
}

void Tile::Debug() {

	if (isMine && !isRevealed) {

		if (isDebug) {
			
			isDebug = false;
			topIcon.setColor(Color(255, 255, 255, 0));

		}
		else {

			isDebug = true;
			topIcon.setColor(Color(255, 255, 255, 255));

		}

	}
}

void Tile::createPauseScreen(bool isPaused) {

	if (isPaused) {

		pauseIcon.setColor(Color(255, 255, 255, 255));
		
	}
	else {

		pauseIcon.setColor(Color(255, 255, 255, 0));

	}
}

bool Tile::Reveal(int& counter) {

	if (!isRevealed && !isFlag)
	{
		isRevealed = true;

		counter++;

		foreground.setColor(Color(255, 255, 255, 0));
		topIcon.setColor(Color(255, 255, 255, 255));

		if (mines == 0 && !isMine) {

			for (int c = 0; c < 8; c++)	{

				if (neighboring[c] != nullptr && !(neighboring[c]->isMine)) {

					neighboring[c]->Reveal(counter);

				}
			}
		}
	}

	return isMine;

}

void Tile::drawWindow(RenderWindow& window_) {

	window_.draw(background);
	window_.draw(foreground);
	window_.draw(topIcon);
	window_.draw(flagIcon);
	window_.draw(pauseIcon);

}

bool Tile::flagStatus() {

	return isFlag;

}