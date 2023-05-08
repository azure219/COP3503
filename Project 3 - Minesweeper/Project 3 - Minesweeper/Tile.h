#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Tile
{
	int xPos, yPos, numAdjacentMines;
	bool isMine, isFlagged, isHidden;
	sf::Sprite bg_sprite, mg_sprite, fg_sprite;
	vector<Tile*> adjacents;

	Tile(map<string, sf::Texture*>& textures, int xPos, int yPos);
	void draw(sf::RenderWindow& window, map<string, sf::Texture*>& textures);
	void flag();
	void reveal();
	void setMineHidden(bool isHidden);
};