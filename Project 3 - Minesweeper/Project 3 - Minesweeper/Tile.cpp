#include "Tile.h"

using namespace std;

Tile::Tile(map<string, sf::Texture*>& textures, int xPos_, int yPos_)
{
	xPos = xPos_;
	yPos = yPos_;
	numAdjacentMines = 0;
	isMine = false;
	isFlagged = false;
	isHidden = true;
	bg_sprite.setPosition(xPos_ * 32, yPos_ * 32);
	mg_sprite.setPosition(xPos_ * 32, yPos_ * 32);
	fg_sprite.setPosition(xPos_ * 32, yPos_ * 32);
}

void Tile::draw(sf::RenderWindow& window, map<string, sf::Texture*>& textures)
{
	if (isHidden)
	{
		bg_sprite.setTexture(*textures["tile_hidden"]);
		if (isFlagged)
			fg_sprite.setTexture(*textures["flag"]);
		else
			fg_sprite.setTexture(*textures["tile_hidden"]);
	}
	else
	{
		bg_sprite.setTexture(*textures["tile_revealed"]);
		if (isMine)
		{
			fg_sprite.setTexture(*textures["mine"]);
			if (isFlagged)
				mg_sprite.setTexture(*textures["flag"]);
		}
		else
		{
			if (numAdjacentMines == 0)
				fg_sprite.setTexture(*textures["tile_revealed"]);
			else
				fg_sprite.setTexture(*textures["number_" + to_string(numAdjacentMines)]);
		}
	}
	window.draw(bg_sprite);
	window.draw(mg_sprite);
	window.draw(fg_sprite);
}

void Tile::flag()
{
	if (isHidden)
		isFlagged = !isFlagged;
}

void Tile::setMineHidden(bool isHidden_)
{
	if (isMine)
		isHidden = isHidden_;
}

void Tile::reveal()
{
	if (!isFlagged && isHidden)
	{
		isHidden = false;
		if (!isMine && numAdjacentMines == 0)
			for (Tile* tile : adjacents)
				tile->reveal();
	}
}