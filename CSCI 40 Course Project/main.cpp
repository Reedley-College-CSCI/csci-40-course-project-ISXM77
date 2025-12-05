// CSCI-40 Course Project
// Name: Issa Martinez

// This Program keeps track of team statistics in a baseball
// game and outputs a scoreboard of the game based off the user's
// input.

// Test Commit

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Game { // class holding functions for entire baseball game
public:
	void Away(int count);
	void Home(int count);
	int printTotalAwayRuns(int count) const;
	int printTotalHomeRuns(int count) const;
	int printTotalAwayHits(int count) const;
	int printTotalHomeHits(int count) const;
	void FirstNineInnings();
	void ExtraInnings();
	string printScoreboard() const;
	void printScoreboardToFile() const;
	void menu();
	int intRange(int lo, int hi);
	int HighScoreInning(bool side) const;
	void printHighScoreInning() const;
private:
	struct Stats { // struct holding stat values
		int outs = 0;
		int hits = 0;
		int runs = 0;
		int onbase = 0;
	};
	static constexpr int MAX_INNINGS = 100; // Maximum array size
	Stats homestats[MAX_INNINGS]; // array of structs to holds stats for home and away
	Stats awaystats[MAX_INNINGS];
	int inning = 0; // inning initialized to 0
};

int main() {
	Game game; // object declaration
	game.FirstNineInnings();// Function calls
	game.ExtraInnings();
	cout << game.printScoreboard() << endl;
	game.printHighScoreInning();
	game.printScoreboardToFile(); // Function outputs to File

}

string Game::printScoreboard() const{
	string scoreboard = "     |  ";
	for (int i = 1; i <= 9; i++) {
		scoreboard += to_string(i);
		scoreboard += "  |  ";
	}
	if (inning > 9) {
		for (int i = 10; i <= inning; i++) {
			scoreboard += to_string(i);
			scoreboard += " |  ";
		}
	}
	scoreboard += "R  |  H  |\n";

	scoreboard += "-----|";
	for (int i = 1; i <= inning; i++) {
		scoreboard += "-----|";
	}
	scoreboard += "-----|-----|\n";

	scoreboard += "  A  |  ";
	for (int i = 1; i <= inning; i++) {
		scoreboard += to_string(awaystats[i].runs);
		scoreboard += "  |  ";
	}
	scoreboard += to_string(printTotalAwayRuns(inning));
	scoreboard += "  |  ";
	scoreboard += to_string(printTotalAwayHits(inning));
	scoreboard += "  |  \n";

	scoreboard += "-----|";
	for (int i = 1; i <= inning; i++) {
		scoreboard += "-----|";
	}
	scoreboard += "-----|-----|\n";

	scoreboard += "  H  |  ";
	for (int i = 1; i <= inning; i++) {
		scoreboard += to_string(homestats[i].runs);
		scoreboard += "  |  ";
	}
	scoreboard += to_string(printTotalHomeRuns(inning));
	scoreboard += "  |  ";
	scoreboard += to_string(printTotalHomeHits(inning));
	scoreboard += "  |  \n";
	
	return scoreboard; // prints scoreboard as a string
}
void Game::Home(int count) {
	int i = count;
	int userInput;
	int onBase;
	if (count == 9 && printTotalAwayRuns(9) < printTotalHomeRuns(9)) return; // if statement ends game if away team fails to score in ninth
	while (homestats[i].outs != 3) {
		if (i >= 10 && printTotalAwayRuns(i) < printTotalHomeRuns(i)) { // if statement ends game if home walks it off in extras
			return;
		}
		if (i == 9 && printTotalAwayRuns(i) < printTotalHomeRuns(i)) { // if statement ends game if home walks it off in ninth
			return;
		}
		cout << "What is the result of the next play in the bottom of inning #" << i << ": ";
		userInput = intRange(1,5);
		int runsScored;
		switch (userInput) {

		case 1: 
			homestats[i].outs += 1; 
			break;
		case 2:
			homestats[i].hits += 1;
			cout << "Runs Scored: ";
			runsScored = intRange(0, 4);
			cout << "On Base: ";
			onBase = intRange(0,3);
			homestats[i].onbase = onBase;
			homestats[i].runs += runsScored;
			break;
		case 3:
			cout << "Runs Scored: ";
			runsScored = intRange(0, 2);
			homestats[i].runs += runsScored;
			break;
		case 4:
			homestats[i].hits += 1;
			runsScored = homestats[i].onbase + 1;
			homestats[i].runs += runsScored;
			homestats[i].onbase = 0;
			onBase = 0;
			break;
		case 5:
			cout << "Runs Scored: ";
			runsScored = intRange(0, 2);
			homestats[i].runs += runsScored;
			break;
		}
	}
	cout << endl;
	return;
}
void Game::Away(int count) {
	menu();
	int i = count;
	int userInput;
	int onBase;
	while (awaystats[i].outs != 3) {
		cout << "What is the result of the next play in the top of inning #" << i << ": ";
		userInput = intRange(1,5);
		int runsScored;
		switch (userInput) {

		case 1: awaystats[i].outs += 1; break;
		case 2:
			awaystats[i].hits += 1;
			cout << "Runs Scored: ";
			runsScored = intRange(0,4);
			cout << "On Base: ";
			onBase = intRange(0,3);
			awaystats[i].onbase = onBase;
			awaystats[i].runs += runsScored;
			break;
		case 3:
			cout << "Runs Scored: ";
			runsScored = intRange(0, 2);
			awaystats[i].runs += runsScored;
			break;
		case 4:
			awaystats[i].hits += 1;
			runsScored = awaystats[i].onbase + 1;
			awaystats[i].runs += runsScored;
			awaystats[i].onbase = 0;
			onBase = 0;
			break;
		case 5:
			cout << "Runs Scored: ";
			runsScored = intRange(0, 2);
			awaystats[i].runs += runsScored;
			break;
		}
	}
	return;
}
int Game::printTotalAwayRuns(int count) const{
	int totalRunsAway = 0;
	for (int i = 1; i <= count; i++) {
		totalRunsAway += awaystats[i].runs;
	}
	return totalRunsAway;
}
int Game::printTotalHomeRuns(int count) const{
	int totalRunsHome = 0;
	for (int i = 1; i <= count; i++) {
		totalRunsHome += homestats[i].runs;
	}
	return totalRunsHome;
}
int Game::printTotalAwayHits(int count) const{
	int totalHitsAway = 0;
	for (int i = 1; i <= count; i++) {
		totalHitsAway += awaystats[i].hits;
	}
	return totalHitsAway;
}
int Game::printTotalHomeHits(int count) const{
	int totalHitsHome = 0;
	for (int i = 1; i <= count; i++) {
		totalHitsHome += homestats[i].hits;
	}
	return totalHitsHome;
}
void Game::FirstNineInnings() {
	for (int i = 1; i <= 9; i++) {
		Away(i);
		Home(i);
		inning = i;
	}
	return;
}
void Game::ExtraInnings() {
	if (printTotalAwayRuns(9) != printTotalHomeRuns(9)) {
		return;
	}
	else {
		int i = 10;
		while (printTotalAwayRuns(i) == printTotalHomeRuns(i)) {
			if (i > 99) {
				cout << "Maximum innings reached, stopping game.\n";// end of array
				return;
			}

			Away(i);
			Home(i);
			i++;
		}
		inning = i - 1;
		return;
	}
}
void Game::printScoreboardToFile() const{
	ofstream outFile("scoreboard.txt");
	if (outFile.is_open()) { // File check
		outFile << printScoreboard();
		outFile.close();
	}
	else {
		cout << "Error: unable to open file: scoreboard.txt" << endl;
		return;
	}
	return;
}
void Game::menu() {
	cout << "1. Out | 2. Hit | 3. Walk | 4. HR | 5. HBP|\n"; // menu displayed to show options to user
	cout << endl;
	return;
}
int Game::intRange(int lo, int hi) {
	int x;
	while (true) {
		if (cin >> x && x >= lo && x <= hi) return x;
		cin.clear();
		cin.ignore();
		cout << "Enter a number between " << lo << " and " << hi << ": ";
	}
}
int Game::HighScoreInning(bool side) const{
	int best = 0;
	int bestruns = -1;
	for (int i = 1; i <= inning; ++i) { // linear search
		int runs;
		if (side) {
			runs = homestats[i].runs;
		}
		else {
			runs = awaystats[i].runs;
		}
		if (runs > bestruns) {
			bestruns = runs;
			best = i;
		}
	}
	return best;
}
void Game::printHighScoreInning() const {
	int bestAway = HighScoreInning(false);
	int bestHome = HighScoreInning(true);
	cout << "Best away inning: " << bestAway << " (" << awaystats[bestAway].runs << " runs)\n";
	cout << "Best home inning: " << bestHome << " (" << homestats[bestHome].runs << " runs)\n";
	return;
}
