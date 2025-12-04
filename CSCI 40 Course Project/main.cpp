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
private:
	struct Stats { // struct holding stat values
		int outs = 0;
		int hits = 0;
		int runs = 0;
	};
	Stats homestats[99]; // array of structs to holds stats for home and away
	Stats awaystats[99];
	int inning = 0; // inning initialized to 0
};

int main() {
	Game game; // object declaration
	game.FirstNineInnings();// Function calls
	game.ExtraInnings();
	cout << game.printScoreboard();
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
	string userstring;
	if (printTotalAwayRuns(9) < printTotalHomeRuns(9)) { // if statement ends game if away team fails to score in ninth
		return;
	}
	while (homestats[i].outs != 3) {
		if (i >= 10 && printTotalAwayRuns(i) < printTotalHomeRuns(i)) { // if statement ends game if home walks it off in extras
			return;
		}
		if (i == 9 && printTotalAwayRuns(i) < printTotalHomeRuns(i)) { // if statement ends game if home walks it off in ninth
			return;
		}
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
				cin >> runsScored;
				cin.ignore();
			}
			homestats[i].runs += runsScored;
		}
	}
	return;
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
				cout << "Maximum innings reached, stopping game.\n";
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
