#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include "welcomeWindow.h"
#include "GW.h"
#include "time.h"

using namespace std;
using namespace sf;

int main() {

	welcomeWindow ww = welcomeWindow();
	ww.runWW();

	if (ww.openNextWindow == true) {

		//cout << ww.playerName << endl;

		sf::RenderWindow window(sf::VideoMode((ww.returnWidth() * 32), ((ww.returnHeight() * 32) + 100)), "Minesweeper");

		gameWindow gamemaster = gameWindow(ww.playerName);

		sf::Clock updateTime;
		sf::Time start = updateTime.getElapsedTime();

		while (window.isOpen()) {

			sf::Time current = updateTime.getElapsedTime();

			sf::Event event;

			if (window.pollEvent(event) || (current - start).asSeconds() >= 1) {

				start = current;
				if (event.type == sf::Event::Closed) window.close();
				window.clear(sf::Color::White);
				gamemaster.update(window);
				window.display();

			}

			

		}

	}

	/*if (ww.openNextWindow == true) {

		sf::RenderWindow gameWindow(sf::VideoMode((ww.returnWidth() * 32), (ww.returnHeight() * 32 + 100)), "Minesweeper | Board 2");

		Board2 gameBoard = Board2();

		while (gameWindow.isOpen() == true) {

			Event gameEvent;

			if (gameWindow.pollEvent(gameEvent) == true) {

				if (gameEvent.type == Event::Closed) {

					gameWindow.close();

				}

				gameWindow.clear(Color::White);
				gameBoard.updateBoard(gameWindow);
				gameWindow.display();

			}

		}

	}*/

	return 0;

}