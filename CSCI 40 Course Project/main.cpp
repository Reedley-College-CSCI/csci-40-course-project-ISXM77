// CSCI-40 Course Project
// Name: Issa Martinez

// This Program keeps track of team statistics in a baseball
// game and outputs a scoreboard of the game based off the user's
// input.

// Test Commit

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Stats { // struct holding stat values
	int outs = 0;
	int hits = 0;
	int runs = 0;
};

class Game { // class holding functions for entire baseball game
public:
	int inning = 0;
	void Away(int count);
	void Home(int count);
	int printTotalAwayRuns(int count);
	int printTotalHomeRuns(int count);
	int printTotalAwayHits(int count);
	int printTotalHomeHits(int count);
	void FirstNineInnings();
	void ExtraInnings();
	void printScoreboard();
	Stats homestats[100]; // array of structs to holds stats for home and away
	Stats awaystats[100];
};

int main() {
	Game game; // Function calls
	game.FirstNineInnings();
	game.ExtraInnings();
	game.printScoreboard();

	return 0;
}

void Game::printScoreboard() {
	cout << "     |  ";
	for (int i = 1; i <= 9; i++) {
		cout << i << "  |  ";
	}
	if (inning > 9) {
		for (int i = 10; i <= inning; i++) {
			cout << i << " |  ";
		}
	}
	cout << "R  |  H  |" << endl;

	cout << "-----|";
	for (int i = 1; i <= inning; i++) {
		cout << "-----|";
	}
	cout << "-----|-----|" << endl;

	cout << "  A  |  ";
	for (int i = 1; i <= inning; i++) {
		cout << awaystats[i].runs << "  |  ";
	}
	cout << printTotalAwayRuns(inning) << "  |  "
		<< printTotalAwayHits(inning) << "  |  " << endl;

	cout << "-----|";
	for (int i = 1; i <= inning; i++) {
		cout << "-----|";
	}
	cout << "-----|-----|" << endl;

	cout << "  H  |  ";
	for (int i = 1; i <= inning; i++) {
		cout << homestats[i].runs << "  |  ";
	}
	cout << printTotalHomeRuns(inning) << "  |  "
		<< printTotalHomeHits(inning) << "  |  " << endl;
}
void Game::Home(int count) {
	int i = count;
	string userstring;
	while (homestats[i].outs != 3) {
		cout << "What is the result of the next play in the bottom of inning #" << i << ": ";
		getline(cin, userstring);
		if (userstring == "out" || userstring == "Out") {
			homestats[i].outs += 1;
		}
		else if (userstring == "hit" || userstring == "Hit") {
			int runsScored;
			homestats[i].hits += 1;
			cout << "Runs Scored: ";
			cin >> runsScored;
			cin.ignore();
			while (runsScored > 4) {
				cout << "Too many, Try Again: ";
				cin >> runsScored;
				cin.ignore();
			}
			homestats[i].runs += runsScored;

		}
		else if (userstring == "walk" || userstring == "Walk") {
			int runsScored;
			cout << "Runs Scored: ";
			cin >> runsScored;
			cin.ignore();
			while (runsScored > 2) {
				cout << "Too many, Try Again: ";
				cin >> count;
				cin.ignore();
			}
			homestats[i].runs += runsScored;
		}
	}
}
void Game::Away(int count) {
	int i = count;
	string userstring;
	while (awaystats[i].outs != 3) {
		cout << "What is the result of the next play in the top of inning #" << i << ": ";
		getline(cin, userstring);
		if (userstring == "out" || userstring == "Out") {
			awaystats[i].outs += 1;
		}
		else if (userstring == "hit" || userstring == "Hit") {
			int runsScored;
			awaystats[i].hits += 1;
			cout << "Runs Scored: ";
			cin >> runsScored;
			cin.ignore();
			while (runsScored > 4) {
				cout << "Too many, Try Again: ";
				cin >> runsScored;
				cin.ignore();
			}
			awaystats[i].runs += runsScored;
		}
		else if (userstring == "walk" || userstring == "Walk") {
			int runsScored;
			cout << "Runs Scored: ";
			cin >> runsScored;
			cin.ignore();
			while (runsScored > 2) {
				cout << "Too many, Try Again: ";
				cin >> runsScored;
				cin.ignore();
			}
			awaystats[i].runs += runsScored;
		}
	}
}
int Game::printTotalAwayRuns(int count) {
	int totalRunsAway = 0;
	for (int i = 1; i <= count; i++) {
		totalRunsAway += awaystats[i].runs;
	}
	return totalRunsAway;
}
int Game::printTotalHomeRuns(int count) {
	int totalRunsHome = 0;
	for (int i = 1; i <= count; i++) {
		totalRunsHome += homestats[i].runs;
	}
	return totalRunsHome;
}
int Game::printTotalAwayHits(int count) {
	int totalHitsAway = 0;
	for (int i = 1; i <= count; i++) {
		totalHitsAway += awaystats[i].hits;
	}
	return totalHitsAway;
}
int Game::printTotalHomeHits(int count) {
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
}
void Game::ExtraInnings() {
	if (printTotalAwayRuns(9) != printTotalHomeRuns(9)) {
		return;
	}
	else {
		int i = 10;
		while (printTotalAwayRuns(i) == printTotalHomeRuns(i)) {
			Away(i);
			Home(i);
			i++;
		}
		inning = i - 1;
		return;
	}
}