#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <random>

#include "Tile.h"

struct Board
{
	enum GameState
	{
		WIN,
		LOSE,
		PLAY,
		DEBUG
	};

	unsigned int numCols, numRows, numMines, numTiles;
	unsigned int height, width;
	int numFlagged, numHidden;
	string currentBoard;
	vector<vector<Tile>> tiles;
	GameState gameState;

	Board();
	void init(map<string, sf::Texture*>& textures, vector<sf::Vector2i>& mines);
	void setMines(vector<sf::Vector2i>& mines);
	void draw(sf::RenderWindow& window, map<string, sf::Texture*>& textures);
	void updateCount();
	void toggleMines();
};
