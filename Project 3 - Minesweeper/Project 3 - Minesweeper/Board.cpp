#include "Board.h"

using namespace std;

Board::Board()
{
	numCols = 0;
	numRows = 0;
	numTiles = 0;
	numMines = 0;
	height = 0;
	width = 0;
	numFlagged = 0;
	numHidden = 0;
	currentBoard = "";
	gameState = PLAY;
}

void Board::init(map<string, sf::Texture*>& textures, vector<sf::Vector2i>& mines)
{
	// Clear board if previously filled
	if (tiles.size() > 0)
	{
		for (vector<Tile> row : tiles)
			tiles.pop_back();
		gameState = PLAY;
	}

	// Fill 2D tile vector
	for (unsigned int y = 0; y < numRows; y++)
	{
		vector<Tile> row;
		for (unsigned int x = 0; x < numCols; x++)
			row.push_back(Tile(textures, x, y));
		tiles.push_back(row);
	}

	setMines(mines);

	// Set adjacents of each tile
	
	for (int y = 0; y < tiles.size(); y++)
	{
		vector<int> adjY;
		for (int x = 0; x < tiles[y].size(); x++)
		{
			vector<int> adjX;
			// Set adjacent rows
			if (y == 0)
				adjY = { y, y + 1 };
			else if (y == numRows - 1)
				adjY = { y - 1, y };
			else
				adjY = { y - 1, y, y + 1 };
			// Set adjacent cols
			if (x == 0)
				adjX = { x, x + 1 };
			else if (x == numCols - 1)
				adjX = { x - 1, x };
			else
				adjX = { x - 1, x, x + 1 };
			// Set adjacent tiles
			int numAdjMines = 0;
			for (int i : adjY)
				for (int j : adjX)
				{
					if (!(x == j && y == i))
					{
						tiles[y][x].adjacents.push_back(&tiles[i][j]);
						if (tiles[i][j].isMine)
							tiles[y][x].numAdjacentMines++;
					}
				}
		}
	}
}

void Board::setMines(vector<sf::Vector2i>& mines)
{
	if (mines.size() > 0)
			for (unsigned int i = 0; i < mines.size(); i++)
				tiles[mines[i].y][mines[i].x].isMine = true;
	else
	{
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> uidX(0, numCols - 1);
		uniform_int_distribution<int> uidY(0, numRows - 1);
		for (unsigned int i = 0; i < numMines;)
		{
			int x = uidX(mt);
			int y = uidY(mt);
			if (!tiles[y][x].isMine)
			{
				tiles[y][x].isMine = true;
				i++;
			}
		}
	}
}

void Board::draw(sf::RenderWindow& window, map<string, sf::Texture*>& textures)
{
	for (unsigned int y = 0; y < tiles.size(); y++)
		for (unsigned int x = 0; x < tiles[y].size(); x++)
			tiles[y][x].draw(window, textures);
}

void Board::updateCount()
{
	numFlagged = 0, numHidden = numTiles;
	for (unsigned int y = 0; y < tiles.size(); y++)
		for (unsigned int x = 0; x < tiles[y].size(); x++)
		{
			if (tiles[y][x].isFlagged)
				numFlagged++;
			if (!tiles[y][x].isHidden)
			{
				numHidden--;
				if (tiles[y][x].isMine && gameState == PLAY)
				{
					gameState = LOSE;
					toggleMines();
				}
			}
		}
	if (gameState == PLAY && numFlagged == numMines && numFlagged == numHidden)
		gameState = WIN;
}

void Board::toggleMines()
{
	if (gameState == PLAY)
	{
		for (unsigned int y = 0; y < tiles.size(); y++)
			for (unsigned int x = 0; x < tiles[y].size(); x++)
				tiles[y][x].setMineHidden(false);
		gameState = DEBUG;
	}
	else if (gameState == DEBUG)
	{
		for (unsigned int y = 0; y < tiles.size(); y++)
			for (unsigned int x = 0; x < tiles[y].size(); x++)
				tiles[y][x].setMineHidden(true);
		gameState = PLAY;
	}
	else if (gameState == LOSE)
	{
		for (unsigned int y = 0; y < tiles.size(); y++)
			for (unsigned int x = 0; x < tiles[y].size(); x++)
				if (tiles[y][x].isMine)
					tiles[y][x].isHidden = false;
	}
}