// CSCI-40 Course Project - Baseball Game Tracker
// Name: Issa Martinez

// This Program keeps track of team statistics in a baseball
// game and outputs a scoreboard of the game based off the user's
// input.

// Test Commit
#include "Game.h"
#include <iostream>

int main() {
	Game game; // object declaration
	game.FirstNineInnings();// Function calls
	game.ExtraInnings();
	std::cout << game.printScoreboard() << std::endl;
	game.printHighScoreInning(); // outputs highest scoring innings
	game.printScoreboardToFile(); // Function outputs to File
	game.printSortedInnings(false);
	std::cout << std::endl;
	game.printSortedInnings(true);
	return 0;
}