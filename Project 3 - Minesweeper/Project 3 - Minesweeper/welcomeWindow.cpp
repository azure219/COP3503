#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include "welcomeWindow.h"
using namespace std;

void welcomeWindow::runWW() {

	ifstream file("files/board_config.cfg");

	for (int i = 0; i < 3; i++) {

		file >> dimensions[i];
		//out << dimensions[i] << " ";

	}

	height = (dimensions[1] * 32 + 100);
	width = (dimensions[0] * 32);

	// <-- Welcome Window Screen Set Up -->

	sf::RenderWindow welWindow(sf::VideoMode(width, height), "MINESWEEPER!");

	sf::Font font;

	if (!font.loadFromFile("files/font.ttf")) {

		cout << "font not loaded :(" << endl;

	}

	// <-- Welcome Text -->

	sf::Text welText;
	welText.setFont(font);
	welText.setString("WELCOME TO MINESWEEPER!");
	welText.setFillColor(sf::Color::White);
	welText.setCharacterSize(24);
	welText.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::FloatRect textRect = welText.getLocalBounds();
	welText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	welText.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f - 150));

	// <-- Input Text -->

	sf::Text inputText;
	inputText.setFont(font);
	inputText.setString("Enter your name:");
	inputText.setFillColor(sf::Color::White);
	inputText.setCharacterSize(20);
	inputText.setStyle(sf::Text::Bold);

	sf::FloatRect textRect2 = inputText.getLocalBounds();
	inputText.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
	inputText.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f - 75));

	// <-- Name Text -->

	sf::Text nameText;
	nameText.setFont(font);
	nameText.setString("|");
	nameText.setFillColor(sf::Color::Yellow);
	nameText.setCharacterSize(18);
	nameText.setStyle(sf::Text::Bold);

	sf::FloatRect textRect3 = nameText.getLocalBounds();
	nameText.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
	nameText.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f - 45));

	sf::String playerInput = "";

	while (welWindow.isOpen()) {

		sf::Event event;

		while (welWindow.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				welWindow.close();

			}

			// Enter Name Code

			if (event.type == sf::Event::TextEntered) {

				if (event.text.unicode == '\b') {

					if (!playerInput.isEmpty()) {

						playerInput.erase(playerInput.getSize() - 1, 1);
						nameText.setString(playerInput + "|");

					}

				}
				else if (isalpha(static_cast<char>(event.text.unicode)) && playerInput.getSize() < 10) {

					if (playerInput.getSize() == 0) {

						playerInput += static_cast<char>(toupper(static_cast<char>(event.text.unicode)));

					}
					else {

						playerInput += static_cast<char>(tolower(static_cast<char>(event.text.unicode)));

					}

					nameText.setString(playerInput + "|");

				}

				sf::FloatRect textRect3 = nameText.getLocalBounds();
				nameText.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
				nameText.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f - 45));

				// Press ENTER key to close window

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && playerInput.getSize() > 0) {

					welWindow.close();
					openNextWindow = true;

				}
			}
		} 

		welWindow.clear(sf::Color::Blue);
		welWindow.draw(welText);
		welWindow.draw(inputText);
		welWindow.draw(nameText);
		welWindow.display();

	}

	playerName = playerInput;

}

void welcomeWindow::runLW() {

	ifstream file2("files/board_config.cfg");

	for (int i = 0; i < 3; i++) {

		file2 >> dimensions[i];
		//out << dimensions[i] << " ";

	}

	int heightL = (dimensions[1] * 16 + 50);
	int widthL = (dimensions[0] * 16);

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

	int counter = 1;

	while (getline(file, line)) {

		char comma = line.find(",");
		string beforeComma = line.substr(0, comma);
		string afterComma = line.substr(comma + 1);

		scores = scores + to_string(counter) + ".\t" + beforeComma + "\t" + afterComma + "\n\n";

		counter++;

	}

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

int welcomeWindow::returnHeight() {

	return dimensions[1];

}

int welcomeWindow::returnWidth() {

	return dimensions[0];

}

int welcomeWindow::returnMineCount() {

	return dimensions[2];

}

int welcomeWindow::returnTileCount() {

	return (height * width);

}