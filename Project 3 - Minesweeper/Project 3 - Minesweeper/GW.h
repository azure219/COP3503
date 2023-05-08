#pragma once
#include <iomanip>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <fstream>
#include <set>
#include "T.h"

using namespace std;
using namespace sf;

class gameWindow {

private:

	int width;
	int height;
	int flagsavailable;
	int numMines;
	int tilesRevealed;
	bool pauseChecker = false;
	bool islost;
	bool isover;
	bool iswon;

	string pn;

	vector<bool> tileIDs;
	map<string, Texture> texturePack;

	Sprite debugicon;
	Sprite Pause;
	Sprite Leaderboard;
	Sprite smileFace;

	Clock timer;
	Time elapsed;
	Time pausedTime;
	Time timeWon;

	Sprite hundreds;
	Sprite tens;
	Sprite ones;
	Sprite negative;

	Sprite secondTens;
	Sprite secondOnes;
	Sprite minuteTens;
	Sprite minuteOnes;

public:

	vector<Tile> tiles;
	bool launchLeaderboard = false;
	int counts = 0;

	// default constructor
	gameWindow(string playerName) {

		pn = playerName;

		ifstream file2("files/board_config.cfg");
		
		for (int i = 0; i < 3; i++) {
		
			switch (i) {
		
			case 0: file2 >> width;
				break;
		
			case 1: file2 >> height;
				break;
		
			case 2: file2 >> numMines;
				break;
		
			}
		
		}
		
		// width = 50;
		// height = 14;
		// numMines = 3;

		flagsavailable = numMines;

		// loads textures
		texturePack["debug"].loadFromFile("files/images/debug.png");
		texturePack["digits"].loadFromFile("files/images/digits.png");
		texturePack["face_happy"].loadFromFile("files/images/face_happy.png");
		texturePack["face_lose"].loadFromFile("files/images/face_lose.png");
		texturePack["face_win"].loadFromFile("files/images/face_win.png");
		texturePack["flag"].loadFromFile("files/images/flag.png");
		texturePack["mine"].loadFromFile("files/images/mine.png");
		texturePack["leaderboard"].loadFromFile("files/images/leaderboard.png");
		texturePack["number_1"].loadFromFile("files/images/number_1.png");
		texturePack["number_2"].loadFromFile("files/images/number_2.png");
		texturePack["number_3"].loadFromFile("files/images/number_3.png");
		texturePack["number_4"].loadFromFile("files/images/number_4.png");
		texturePack["number_5"].loadFromFile("files/images/number_5.png");
		texturePack["number_6"].loadFromFile("files/images/number_6.png");
		texturePack["number_7"].loadFromFile("files/images/number_7.png");
		texturePack["number_8"].loadFromFile("files/images/number_8.png");
		texturePack["pause"].loadFromFile("files/images/pause.png");
		texturePack["play"].loadFromFile("files/images/play.png");
		texturePack["tile_hidden"].loadFromFile("files/images/tile_hidden.png");
		texturePack["tile_revealed"].loadFromFile("files/images/tile_revealed.png");

		// sets locations and textures
		debugicon.setTexture(texturePack["debug"]);
		debugicon.setPosition((width * 32) - 304, 32 * (height + 0.5f));
		Pause.setTexture(texturePack["pause"]);
		Pause.setPosition((width * 32) - 240, 32 * (height + 0.5f));
		Leaderboard.setTexture(texturePack["leaderboard"]);
		Leaderboard.setPosition((width * 32) - 176, 32 * (height + 0.5f));
		smileFace.setTexture(texturePack["face_happy"]);
		smileFace.setPosition(((width / 2.0) * 32) - 32, 32 * (height + 0.5f));
		hundreds.setTexture(texturePack["digits"]);
		hundreds.setTextureRect(Rect<int>(0, 0, 21, 32));
		hundreds.setPosition(33, 32 * (height + 0.5f) + 16);
		tens.setTexture(texturePack["digits"]);
		tens.setTextureRect(Rect<int>(0, 0, 21, 32));
		tens.setPosition(54, 32 * (height + 0.5f) + 16);
		ones.setTexture(texturePack["digits"]);
		ones.setTextureRect(Rect<int>(0, 0, 21, 32));
		ones.setPosition(75, 32 * (height + 0.5f) + 16);
		negative.setTexture(texturePack["digits"]);
		negative.setPosition(12, 32 * (height + 0.5f) + 16);
		negative.setColor(Color(255, 255, 255, 0));

		int xPos = ((width * 32) - 54);
		int yPos = (32 * (height + 0.5f) + 16);

		secondTens.setTexture(texturePack["digits"]);
		secondTens.setPosition(xPos, yPos);
		xPos += 21;
		secondOnes.setTexture(texturePack["digits"]);
		secondOnes.setPosition(xPos, yPos);

		xPos = ((width * 32) - 97);
		minuteTens.setTexture(texturePack["digits"]);
		minuteTens.setPosition(xPos, yPos);
		xPos += 21;
		minuteOnes.setTexture(texturePack["digits"]);
		minuteOnes.setPosition(xPos, yPos);

		createTiles();
		Reset();

	}

	// board creation functions
	void Reset();
	void update(RenderWindow& window);
	void draw(RenderWindow& window);
	void createTiles();
	void setMineStates();
	void setIcons();
	

	// buttons/other functions
	void debug();
	void pauser(bool p);
	void refreshFlagCounter();
	void refreshSmileFace();
	void createPauseScreen();
	void refreshTimer();

};

// board creation functions

void gameWindow::Reset() {

	tileIDs.clear();
	counts = 0;

	map<int, int> mineLocations;
	set<int> mineSet;

	for (int i = 0; i < (width * height); i++) {

		tileIDs.push_back(false);

	}

	while (mineSet.size() < numMines) {

		mineSet.emplace(rand() % (width * height));

	}

	for (set<int>::iterator itr = mineSet.begin(); itr != mineSet.end(); itr++) {

		mineLocations[*itr] = *itr;
		tileIDs[(*itr)] = (*itr);
	
	}

	cout << "tileIDs size: " << tileIDs.size() << endl;

	setMineStates();
	setIcons();
	flagsavailable = numMines;
	refreshFlagCounter();
	tilesRevealed = 0;

	islost = false;
	isover = false;
	iswon = false;

	Pause.setTexture(texturePack["pause"]);
	pauseChecker = false;

	timer.restart();
	elapsed = timer.getElapsedTime();

}

void gameWindow::update(RenderWindow& window) {

	//draw(window);

	// left click on window
	if (Mouse::isButtonPressed(Mouse::Left)) {

		Vector2i mousePosition = Mouse::getPosition(window);

		// clicking on the game board
		if (mousePosition.y >= 0 && mousePosition.y < (height * 32) && (isover == false) && (pauseChecker == false)) {

			int x = (mousePosition.x / 32); // if something goes wrong
			int y = (mousePosition.y / 32); // this code plus the 
			// next // is what was
			int pos = (y * width) + x;		// changed from the last

			if (mousePosition.x >= 0 && mousePosition.x <= (width * 32) && !tiles[pos].isFlag) { // successfull version.

				int count = 0;

				if (tiles[pos].Reveal(count) && !tiles[pos].isFlag) {

					islost = true;
					isover = true;

					int dummycount = 0;

					for (int c = 0; c < (width * height); c++) {

						if (tiles[c].isFlag && tiles[c].isMine) {

							tiles[c].Flag();

						}

						if (tiles[c].isMine) {

							tiles[c].Reveal(dummycount);

						}

					}
				}
				else { // also the only other change made is putting brackets on this else statement

					tilesRevealed = tilesRevealed + count;

				}

			}

		}

		// clicking on buttons board
		else if (mousePosition.y >= (height * 32) && mousePosition.y < ((height * 32) + 60)) {

			Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));

			// retrieve the bounding box of the sprite
			FloatRect smileButton = smileFace.getGlobalBounds();
			FloatRect leaderboardButton = Leaderboard.getGlobalBounds();
			FloatRect pauseButton = Pause.getGlobalBounds();
			FloatRect debugButton = debugicon.getGlobalBounds();

			// hit tests
			if (smileButton.contains(mouse)) {

				Reset();
				pauser(false);
				//refreshSmileFace();
				//timer.restart();
				pausedTime = timer.restart();

			}

			if (leaderboardButton.contains(mouse)) {

				/*if (launchLeaderboard == false) {

					pausedTime += timer.getElapsedTime();

					pauser(true);
					launchLeaderboard = true;

				}
				else if (launchLeaderboard == true) {

					timer.restart();

					pauser(false);
					launchLeaderboard = false;

				}*/

				if (pauseChecker == false) {

					Pause.setTexture(texturePack["play"]);
					pausedTime += timer.getElapsedTime();
					pauseChecker = true;
					pauser(pauseChecker);

					if (pauseChecker == true) {

						int heightL = (height * 16 + 50);
						int widthL = (width * 16);
						map<int, string> scoresList;

						// <-- Welcome Window Screen Set Up -->

						sf::RenderWindow lWindow(sf::VideoMode(widthL, heightL), "LEADERBOARD!");

						sf::Font font;

						if (!font.loadFromFile("files/font.ttf")) {

							cout << "font not loaded :(" << endl;

						}

						// <-- Welcome Text -->

						sf::Text welText;
						welText.setFont(font);
						welText.setString("LEADERBOARD");
						welText.setFillColor(sf::Color::White);
						welText.setCharacterSize(20);
						welText.setStyle(sf::Text::Bold | sf::Text::Underlined);

						sf::FloatRect textRect = welText.getLocalBounds();
						welText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
						welText.setPosition(sf::Vector2f(widthL / 2.0f, heightL / 2.0f - 120));

						// <-- Input Text -->

						ifstream file("files/leaderboard.txt");
						string line;
						string scores;

						while (getline(file, line)) {

							char comma = line.find(",");
							char colon = line.find(":");
							string beforeComma = line.substr(0, comma);
							string beforeColon = line.substr(0, colon);
							string afterColon = line.substr(colon + 1);
							string afterComma = line.substr(comma + 1);

							int rawTime = stoi(beforeColon + afterColon);
							scoresList.emplace(rawTime, afterComma);

							//scores = scores + to_string(counter) + ".\t" + beforeComma + "\t" + afterComma + "\n\n";
							//cout << "Raw Time: " << rawTime << endl;

						}

						int counter2 = 1;

						for (map<int, string>::iterator itr = scoresList.begin(); itr != scoresList.end(); itr++) {

							if (counter2 < 6) {

								int minInt = (itr->first / 60);
								string minStr = to_string(minInt);
								int secInt = (itr->first % 60);
								string secStr = to_string(secInt);

								if (minInt < 10) {

									minStr = ("0" + minStr);

								}

								if (secInt < 10) {

									secStr = ("0" + secStr);

								}

								string cleanScore = (minStr + ":" + secStr);

								scores = scores + to_string(counter2) + ".\t" + cleanScore + "\t" + itr->second + "\n\n";

							}

							counter2++;

						}

						cout << scores << endl;

						sf::Text inputText;
						inputText.setFont(font);
						inputText.setString(scores);
						inputText.setFillColor(sf::Color::White);
						inputText.setCharacterSize(18);
						inputText.setStyle(sf::Text::Bold);

						sf::FloatRect textRect2 = inputText.getLocalBounds();
						inputText.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
						inputText.setPosition(sf::Vector2f(widthL / 2.0f, heightL / 2.0f + 30));

						while (lWindow.isOpen()) {

							sf::Event e;

							while (lWindow.pollEvent(e)) {

								if (e.type == sf::Event::Closed) {

									lWindow.close();

								}

							}

							lWindow.clear(sf::Color::Blue);
							lWindow.draw(welText);
							lWindow.draw(inputText);
							lWindow.display();

						}

					}


				}
				if (pauseChecker == true) {

					timer.restart();

					Pause.setTexture(texturePack["pause"]);
					pauseChecker = false;
					pauser(pauseChecker);

				}

			}

			if (pauseButton.contains(mouse) && !isover) {

				// cout << "PAUSED!" << endl;

				if (pauseChecker == false) {

					Pause.setTexture(texturePack["play"]);
					pausedTime += timer.getElapsedTime();
					pauseChecker = true;
					pauser(pauseChecker);

				}
				else if (pauseChecker == true) {

					timer.restart();

					Pause.setTexture(texturePack["pause"]);
					pauseChecker = false;
					pauser(pauseChecker);

				}

			}

			if (debugButton.contains(mouse) && (pauseChecker == false)) {

				debug();

			}

		}
	}

	// game defeat
	if (!islost && tilesRevealed == ((width * height) - numMines)) {

		isover = true;

		for (int e = 0; e < (width * height); e++) {

			if (tiles[e].isMine && !tiles[e].isFlag) {

				tiles[e].Flag();

			}
		}
	}

	// game victory
	if (!islost && ((width * height) == numMines + tilesRevealed)) {

		// player wins
		isover = true;
		//iswon = true;
		timeWon = timer.getElapsedTime();

		if (isover == true && counts < 1) {

			fstream file("files/leaderboard.txt", ios_base::app);

			int rawScore = timeWon.asSeconds();

			int minInt = (rawScore / 60);
			string minStr = to_string(minInt);
			int secInt = (rawScore % 60);
			string secStr = to_string(secInt);

			if (minInt < 10) {

				minStr = ("0" + minStr);

			}

			if (secInt < 10) {

				secStr = ("0" + secStr);

			}

			string cleanScore = (minStr + ":" + secStr);

			file << endl << cleanScore + "," + pn + "*";

			counts = 2;

		}

		//counts = 0;

	}

	// right click to flag
	if (Mouse::isButtonPressed(Mouse::Right) && !isover && (pauseChecker == false)) {

		Vector2i mousePosition = Mouse::getPosition(window);

		if (mousePosition.x >= 0 && mousePosition.x <= (width * 32)) {

			if (mousePosition.y >= 0 && mousePosition.y <= (height * 32))
			{
				int x = (mousePosition.x / 32);
				int y = (mousePosition.y / 32);

				int pos = (y * width) + x;

				if (!tiles[pos].isFlag && !tiles[pos].isRevealed) {

					tiles[pos].Flag();
					flagsavailable--;
					refreshFlagCounter();

				}
				else if (!tiles[pos].isRevealed && tiles[pos].isFlag) {

					tiles[pos].Flag();
					flagsavailable++;
					refreshFlagCounter();

				}


			}
		}
	}

	bool stopTime = false;

	refreshSmileFace();

	if (isover == false) {
		refreshTimer();
	}

	// refresh screen
	draw(window);
}

void gameWindow::draw(RenderWindow& window) {

	// draws tiles
	for (int i = 0; i < (width * height); i++) {

		tiles[i].drawWindow(window);

	}

	// draws everything else
	window.draw(smileFace);
	window.draw(debugicon);
	window.draw(Pause);
	window.draw(Leaderboard);

	window.draw(hundreds);
	window.draw(tens);
	window.draw(ones);
	window.draw(negative);

	window.draw(secondTens);
	window.draw(secondOnes);
	window.draw(minuteTens);
	window.draw(minuteOnes);

}

void gameWindow::createTiles() {

	float x = 0;
	float y = 0;

	for (int i = 0; i < height; i++) {

		for (int n = 0; n < width; n++) {

			Tile tileT = Tile(texturePack, x, y);

			tiles.push_back(tileT);

			x = x + 32.f;

		}

		x = 0;
		y = y + 32.f;

	}
}

void gameWindow::setMineStates() {

	for (int i = 0; i < (width * height); i++) {

		tiles[i].setMineStatus(tileIDs[i]);
	
	}

}

void gameWindow::setIcons() {

	for (int i = 0; i < (width * height); i++) {

		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);
		tiles[i].neighboring.push_back(nullptr);

		if (i == 0) { // top left corner tiel

			tiles[i].neighboring[4] = &(tiles[i + 1]);
			tiles[i].neighboring[6] = &(tiles[i + width]);
			tiles[i].neighboring[7] = &(tiles[i + (width + 1)]);

		}
		else if (i == (width - 1)) { // top right corner tile

			tiles[i].neighboring[3] = &(tiles[i - 1]);
			tiles[i].neighboring[5] = &(tiles[i + (width - 1)]);
			tiles[i].neighboring[6] = &(tiles[i + width]);

		}
		else if (i == ((width * height) - (width))) { // bottom left corner tiel

			tiles[i].neighboring[4] = &(tiles[i + 1]);
			tiles[i].neighboring[1] = &(tiles[i - width]);
			tiles[i].neighboring[2] = &(tiles[i - (width - 1)]);

		}
		else if (i == ((width * height) - 1)) { // bottom right corner

			tiles[i].neighboring[3] = &(tiles[i - 1]);
			tiles[i].neighboring[1] = &(tiles[i - width]);
			tiles[i].neighboring[0] = &(tiles[i - (width + 1)]);

		}
		else if (i < (width - 1)) { // top side tiles

			tiles[i].neighboring[3] = &(tiles[i - 1]);
			tiles[i].neighboring[4] = &(tiles[i + 1]);
			tiles[i].neighboring[5] = &(tiles[i + (width - 1)]);
			tiles[i].neighboring[6] = &(tiles[i + (width)]);
			tiles[i].neighboring[7] = &(tiles[i + (width + 1)]);

		}
		else if (i > ((width * height) - (width))) { // bottom side tiles

			tiles[i].neighboring[3] = &(tiles[i - 1]);
			tiles[i].neighboring[4] = &(tiles[i + 1]);
			tiles[i].neighboring[2] = &(tiles[i - (width - 1)]);
			tiles[i].neighboring[1] = &(tiles[i - width]);
			tiles[i].neighboring[0] = &(tiles[i - (width + 26)]);

		}
		else if ((i % width) == 0) { // left side tiles

			tiles[i].neighboring[4] = &(tiles[i + 1]);
			tiles[i].neighboring[6] = &(tiles[i + width]);
			tiles[i].neighboring[7] = &(tiles[i + (width + 1)]);
			tiles[i].neighboring[1] = &(tiles[i - width]);
			tiles[i].neighboring[2] = &(tiles[i - (width - 1)]);

		}
		else if (((i - 24) % 25) == 0) { // rigth side tiles

			tiles[i].neighboring[3] = &(tiles[i - 1]);
			tiles[i].neighboring[0] = &(tiles[i - (width + 1)]);
			tiles[i].neighboring[1] = &(tiles[i - width]);
			tiles[i].neighboring[5] = &(tiles[i + (width - 1)]);
			tiles[i].neighboring[6] = &(tiles[i + width]);

		}
		else { // middle tiles

			tiles[i].neighboring[3] = &(tiles[i - 1]);
			tiles[i].neighboring[0] = &(tiles[i - (width + 1)]);
			tiles[i].neighboring[1] = &(tiles[i - width]);
			tiles[i].neighboring[5] = &(tiles[i + (width - 1)]);
			tiles[i].neighboring[6] = &(tiles[i + width]);
			tiles[i].neighboring[4] = &(tiles[i + 1]);
			tiles[i].neighboring[7] = &(tiles[i + (width + 1)]);
			tiles[i].neighboring[2] = &(tiles[i - (width - 1)]);

		}

		tiles[i].updateIcon(texturePack);

	}
}


// buttons/other functions

void gameWindow::debug()
{
	for (int i = 0; i < (width * height); i++) {

		if (tiles[i].isFlag == false) {

			tiles[i].Debug();

		}

	}
}

void gameWindow::pauser(bool p)
{
	for (int i = 0; i < (width * height); i++) {

		tiles[i].createPauseScreen(p);

	}
}

void gameWindow::refreshSmileFace() {

	if (isover == true) {

		if (islost == true) {

			smileFace.setTexture(texturePack["face_lose"]);

		}
		else {

			smileFace.setTexture(texturePack["face_win"]);
			flagsavailable = 0;
			refreshFlagCounter();

			fstream lfile;

		}

	}
	else {

		smileFace.setTexture(texturePack["face_happy"]);

	}

}

void gameWindow::refreshFlagCounter() {

	int copy = flagsavailable;

	negative.setTextureRect(Rect<int>(21 * 10, 0, 21, 32));

	if (copy < 0) {

		negative.setColor(Color(255, 255, 255, 255));
		copy = copy * -1;

	}
	else {

		negative.setColor(Color(255, 255, 255, 0));

	}

	int onesPlace = copy % 10;
	copy = copy / 10;
	int tensPlace = copy % 10;
	copy = copy / 10;
	int hundredsPlace = copy % 10;

	tens.setTextureRect(Rect<int>(21 * tensPlace, 0, 21, 32));
	ones.setTextureRect(Rect<int>(21 * onesPlace, 0, 21, 32));
	hundreds.setTextureRect(Rect<int>(21 * hundredsPlace, 0, 21, 32));

}

void gameWindow::createPauseScreen() {

	if (pauseChecker == false || launchLeaderboard == false) {

		//pausedTime += timer.getElapsedTime();
		Pause.setTexture(texturePack["play"]);
		pauseChecker = true;

	}
	else if (pauseChecker == true || launchLeaderboard == true) {

		//timer.restart();
		Pause.setTexture(texturePack["pause"]);
		pauseChecker = false;

	}

}

void gameWindow::refreshTimer() {

	if (pauseChecker) return;

	elapsed = timer.getElapsedTime() + pausedTime;

	int allSecs = static_cast<int>(elapsed.asSeconds());
	int seconds = allSecs % 60;
	int minutes = allSecs / 60;

	int num1, num2;
	num1 = seconds % 10;
	secondOnes.setTextureRect(Rect<int>(21 * num1, 0, 21, 32));

	seconds = seconds / 10;
	num2 = seconds % 10;
	secondTens.setTextureRect(Rect<int>(21 * num2, 0, 21, 32));

	num1 = minutes % 10;
	minutes = seconds / 10;
	num2 = minutes % 10;
	minuteOnes.setTextureRect(Rect<int>(21 * num1, 0, 21, 32));
	minuteTens.setTextureRect(Rect<int>(21 * num2, 0, 21, 32));


}