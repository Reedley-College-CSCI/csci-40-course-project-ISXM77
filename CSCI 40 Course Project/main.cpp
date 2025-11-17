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

class Inning {
public:
	void incrementHits();
	void incrementRuns();
	void incrementOuts();
	int printInning();
	int printHits();
	int printRuns();
	int printOuts();
	void resetOuts();
	Inning(int i);
private:
	string userstring;
	int inning = 1;
	int hits = 0;
	int runs = 0;
	int outs = 0;
};

int main() {
	Inning AwayInning1(1);
	Inning HomeInning1(1);
	Inning AwayInning2(2);
	Inning HomeInning2(2);

	cout << HomeInning1.printInning() << endl;
	cout << "--" << endl;
	cout << AwayInning1.printRuns() << endl;
	cout << "--" << endl;
	cout << HomeInning1.printRuns() << endl;
	cout << "--" << endl << endl;



	cout << HomeInning2.printInning() << endl;
	cout << "--" << endl;
	cout << AwayInning2.printRuns() << endl;
	cout << "--" << endl;
	cout << HomeInning2.printRuns() << endl;
	cout << "--" << endl << endl;

	void resetOuts();

}
void Inning::resetOuts() {
	outs = 0;
}
int Inning::printInning() {
	return inning;
}
int Inning::printHits() {
	return hits;
}
int Inning::printOuts() {
	return outs;
}
int Inning::printRuns() {
	return runs;
}
void Inning::incrementHits() {
	hits += 1;
}
void Inning::incrementOuts() {
	outs += 1;
}
void Inning::incrementRuns() {
	runs += 1;
}
Inning::Inning(int i) {
	inning = i;
	while (printOuts() < 3) {
		cout << "What is the result of the next play in inning #" << i << ": ";
		getline(cin, userstring);
		if (userstring == "Out" || userstring == "out") {
			incrementOuts();
		}
		else if (userstring == "Hit" || userstring == "hit") {
			incrementHits();
		}
		else if (userstring == "Run" || userstring == "run") {
			int amount;
			cout << "How many runs scored?: ";
			cin >> amount;
			for (int i = 0; i < amount; i++) {
				incrementRuns();
			}
			incrementHits();
			cin.ignore();
		}
	}
}