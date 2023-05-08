//#pragma once
//#include <SFML/Graphics.hpp>
//#include <string>
//using namespace sf;
//using namespace std;
//
//class Tile
//{
//	Sprite background;
//	Sprite foreground;
//	Sprite icon;
//	Sprite flagicon;
//
//
//	bool isdebug;
//
//public:
//	vector<Tile*> neighbors;
//	int numbombs;
//	bool isbomb;
//	bool isflagged;
//	bool isrevealed;
//
//	Tile(map<string, Texture>& textures, float xpos, float ypos);
//	void setBombState(bool bombstate);
//	void updateIcon(map<string, Texture>& textures);
//
//	bool toggleFlag();
//	void toggleDebug();
//	bool reveal(int& counter);
//	void draw(RenderWindow& w);
//};
//
////passes the tile its hidden, revealed, and tile textures, as well as its position. these remain static across all games
////all bools are initialized to false, and should be updated in later instructions
//Tile::Tile(map<string, Texture>& textures, float xpos, float ypos)
//{
//	background.setPosition(xpos, ypos);
//	foreground.setPosition(xpos, ypos);
//	flagicon.setPosition(xpos, ypos);
//	icon.setPosition(xpos, ypos);
//
//	background.setTexture(textures["revealed"]);
//	foreground.setTexture(textures["hidden"]);
//	flagicon.setTexture(textures["flag"]);
//
//	flagicon.setColor(Color(255, 255, 255, 0));
//	isbomb = false;
//	isrevealed = false;
//	isflagged = false;
//	isdebug = false;
//}
//
////sets whether or not this tile should be a bomb this game
//void Tile::setBombState(bool bombstate)
//{
//	isbomb = bombstate;
//}
//
////passes the tile its appropriate icon for this game, and then hides the icon, hides the flag, and shows the hidden texture
////this is the board reset function, usable whenever the game is reset, for any reason, with any button
//void Tile::updateIcon(map<string, Texture>& textures)
//{
//	numbombs = 0;
//	for (int c = 0; c < 8; c++)
//	{
//		if (neighbors[c] != nullptr && neighbors[c]->isbomb)
//		{
//			numbombs++;
//		}
//	}
//	if (isbomb)
//		icon.setTexture(textures["bomb"]);
//	else
//	{
//		switch (numbombs)
//		{
//		case 1: icon.setTexture(textures["one"]); break;
//		case 2: icon.setTexture(textures["two"]); break;
//		case 3: icon.setTexture(textures["three"]); break;
//		case 4: icon.setTexture(textures["four"]); break;
//		case 5: icon.setTexture(textures["five"]); break;
//		case 6: icon.setTexture(textures["six"]); break;
//		case 7: icon.setTexture(textures["seven"]); break;
//		case 8: icon.setTexture(textures["eight"]); break;
//		default: icon.setTexture(textures["revealed"]); break;
//		}
//	}
//	icon.setColor(Color(255, 255, 255, 0));
//	flagicon.setColor(Color(255, 255, 255, 0));
//	foreground.setColor(Color(255, 255, 255, 255));
//	isrevealed = false;
//	isflagged = false;
//	isdebug = false;
//}
//
////hides the flag if it is place, and reveals the flag if it is not yet placed
////if the tile has been revealed, it does nothing
//bool Tile::toggleFlag()
//{
//	if (!isrevealed)
//	{
//		if (isflagged)
//		{
//			isflagged = false;
//			flagicon.setColor(Color(255, 255, 255, 0));
//		}
//		else
//		{
//			isflagged = true;
//			flagicon.setColor(Color(255, 255, 255, 255));
//		}
//	}
//	return isflagged;
//}
//
////reveals bomb icons if they are hidden, and hides them if they are revealed
//void Tile::toggleDebug()
//{
//	if (isbomb && !isrevealed)
//	{
//		if (isdebug)
//		{
//			isdebug = false;
//			icon.setColor(Color(255, 255, 255, 0));
//		}
//		else
//		{
//			isdebug = true;
//			icon.setColor(Color(255, 255, 255, 255));
//		}
//	}
//}
//
////if the tile has not already been revealed, hides foreground and reveals icon. returns isbomb
////if the tile has already been revealed, it does nothing
//bool Tile::reveal(int& counter)
//{
//	if (!isrevealed && !isflagged)
//	{
//		isrevealed = true;
//		counter++;
//		foreground.setColor(Color(255, 255, 255, 0));
//		icon.setColor(Color(255, 255, 255, 255));
//		if (numbombs == 0 && !isbomb)
//		{
//			for (int c = 0; c < 8; c++)
//			{
//				if (neighbors[c] != nullptr && !(neighbors[c]->isbomb))
//					neighbors[c]->reveal(counter);
//			}
//		}
//	}
//	if (!isflagged) {
//
//		return isbomb;
//
//	}
//
//	return NULL;
//
//}
//
////draws the tile, from bottom to top: revealed, hidden, icon, flag
//void Tile::draw(RenderWindow& w)
//{
//	w.draw(background);
//	w.draw(foreground);
//	w.draw(icon);
//	w.draw(flagicon);
//}