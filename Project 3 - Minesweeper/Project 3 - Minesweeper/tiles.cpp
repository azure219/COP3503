//
//#include "tiles.h"
//using namespace std;
//
//tile::tile(map<string, sf::Texture>& texture, float x, float y) {
//
//	background.setPosition(x, y);
//	foreground.setPosition(x, y);
//	topIcon.setPosition(x, y);
//	flagIcon.setPosition(x, y);
//
//	background.setTexture(texture["tile_revealed"]);
//	foreground.setTexture(texture["tile_hidden"]);
//	flagIcon.setTexture(texture["flag"]);
//
//	isMine = false;
//	revealed = false;
//	hasFlag = false;
//	debug = false;
//	mines = 0; // different from source
//
//	flagIcon.setColor(sf::Color(255, 255, 255, 0));
//
//}
//
//void tile::createMine(bool mineStatus) {
//
//	isMine = mineStatus;
//
//}
//
//void tile::updateIcon(map<string, sf::Texture>& textures) {
//
//	for (int i = 0; i < 8; i++) {
//
//		if (neighboring.at(i)->isMine == true) {
//
//			mines++;
//
//		}
//
//	}
//
//	if (isMine == true) {
//
//		topIcon.setTexture(textures["bomb"]);
//
//	}
//	else if (mines = 1) {
//
//		topIcon.setTexture(textures["number_1"]);
//
//	}
//	else if (mines = 2) {
//
//		topIcon.setTexture(textures["number_2"]);
//
//	}
//	else if (mines = 3) {
//
//		topIcon.setTexture(textures["number_3"]);
//
//	}
//	else if (mines = 4) {
//
//		topIcon.setTexture(textures["number_4"]);
//
//	}
//	else if (mines = 5) {
//
//		topIcon.setTexture(textures["number_5"]);
//
//	}
//	else if (mines = 6) {
//
//		topIcon.setTexture(textures["number_6"]);
//
//	}
//	else if (mines = 7) {
//
//		topIcon.setTexture(textures["number_7"]);
//
//	}
//	else if (mines = 8) {
//
//		topIcon.setTexture(textures["number_8"]);
//
//	}
//	else {
//
//		topIcon.setTexture(textures["tile_revealed"]);
//
//	}
//
//	topIcon.setColor(sf::Color(255, 255, 255, 0));
//	flagIcon.setColor(sf::Color(255, 255, 255, 0));
//	foreground.setColor(sf::Color(255, 255, 255, 255));
//	revealed = false;
//	hasFlag = false;
//	debug = false;
//
//}
//
//bool tile::Flag() {
//
//	if (revealed == false) {
//
//		if (hasFlag == true) {
//
//			hasFlag = false;
//			flagIcon.setColor(sf::Color(255, 255, 255, 0));
//
//		}
//		else if (hasFlag == false) {
//
//			hasFlag = true;
//			flagIcon.setColor(sf::Color(255, 255, 255, 255));
//
//		}
//
//	}
//
//	return hasFlag;
//
//}
//
//void tile::Debug() {
//
//	if (debug == false) {
//
//		if (debug == true) {
//
//			debug = false;
//			topIcon.setColor(sf::Color(255, 255, 255, 0));
//
//		}
//		else if (debug == false) {
//
//			debug = true;
//			topIcon.setColor(sf::Color(255, 255, 255, 255));
//
//		}
//	}
//}
//
//bool tile::Reveal(int& counter) {
//
//	if (revealed == false && hasFlag == false) {
//
//		revealed = true;
//		counter++;
//
//		topIcon.setColor(sf::Color(255, 255, 255, 0));
//		foreground.setColor(sf::Color(255, 255, 255, 255));
//
//		if (isMine == false && mines == 0) {
//
//			for (int i = 0; i < 8; i++) {
//
//				if (neighboring.at(i) != nullptr && neighboring.at(i)->isMine == false) {
//
//					neighboring.at(i)->Reveal(counter);
//
//				}
//
//			}
//
//
//		}
//
//	}
//
//	return isMine;
//
//}
//
//void tile::Create(sf::RenderWindow& window) {
//
//	window.draw(background);
//	window.draw(foreground);
//	window.draw(topIcon);
//	window.draw(flagIcon);
//
//}
