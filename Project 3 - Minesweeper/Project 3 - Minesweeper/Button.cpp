#include "Button.h"

Button::Button() {};

Button::Button(sf::Texture* texture, int xPos_, int yPos_)
{
	xPos = xPos_;
	yPos = yPos_;
	width = texture->getSize().x;
	height = texture->getSize().y;
	sprite.setPosition(xPos, yPos);
	sprite.setTexture(*texture);
}

void Button::setTexture(sf::Texture* texture)
{
	sprite.setTexture(*texture);
}

bool Button::isClicked(int x, int y)
{
	if (x >= xPos && x <= xPos + width && y >= yPos && y <= yPos + height)
		return true;
	return false;
}