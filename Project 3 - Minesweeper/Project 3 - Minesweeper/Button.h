#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

struct Button
{
	int xPos, yPos, width, height;
	sf::Sprite sprite;
	Button();
	Button(sf::Texture* texture, int xPos = 0, int yPos = 0);
	void setTexture(sf::Texture* texture);
	bool isClicked(int x, int y);
};