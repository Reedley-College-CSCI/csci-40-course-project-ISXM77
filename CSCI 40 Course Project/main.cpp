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
	// Function Prototypes
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
	// Event variables
	string userstring;
	int inning = 1;
	int hits = 0;
	int runs = 0;
	int outs = 0;
};

int main() {
	Inning AwayInning1(1); // Inning 1
	Inning HomeInning1(1);
	void resetOuts();
	Inning AwayInning2(2); // Inning 1
	Inning HomeInning2(2); 
	void resetOuts();
	Inning AwayInning3(3); // Inning 3
	Inning HomeInning3(3);
	void resetOuts();
	Inning AwayInning4(4); // Inning 4
	Inning HomeInning4(4);
	void resetOuts();
	Inning AwayInning5(5); // Inning 5
	Inning HomeInning5(5);
	void resetOuts();
	Inning AwayInning6(6); // Inning 6
	Inning HomeInning6(6);
	void resetOuts();
	Inning AwayInning7(7); // Inning 7
	Inning HomeInning7(7);
	void resetOuts();
	Inning AwayInning8(8); // Inning 8
	Inning HomeInning8(8);
	void resetOuts();
	Inning AwayInning9(9); // Inning 9
	Inning HomeInning9(9);

	int runtotalHome = HomeInning1.printRuns() + // adds together all runs for Home side
		HomeInning2.printRuns() +
		HomeInning3.printRuns() +
		HomeInning4.printRuns() +
		HomeInning5.printRuns() +
		HomeInning6.printRuns() +
		HomeInning7.printRuns() +
		HomeInning8.printRuns() +
		HomeInning9.printRuns();
	int runtotalAway = AwayInning1.printRuns() + // adds together all runs for Away side
		AwayInning2.printRuns() +
		AwayInning3.printRuns() +
		AwayInning4.printRuns() +
		AwayInning5.printRuns() +
		AwayInning6.printRuns() +
		AwayInning7.printRuns() +
		AwayInning8.printRuns() +
		AwayInning9.printRuns();
	int totalHitsAway = AwayInning1.printHits() + // adds together all hits for Away side
		AwayInning2.printHits() +
		AwayInning3.printHits() +
		AwayInning4.printHits() +
		AwayInning5.printHits() +
		AwayInning6.printHits() +
		AwayInning7.printHits() +
		AwayInning8.printHits() +
		AwayInning9.printHits();
	int totalHitsHome = HomeInning1.printHits() + // adds together all hits for Home side
		HomeInning2.printHits() +
		HomeInning3.printHits() +
		HomeInning4.printHits() +
		HomeInning5.printHits() +
		HomeInning6.printHits() +
		HomeInning7.printHits() +
		HomeInning8.printHits() +
		HomeInning9.printHits();

	cout << endl << endl;
	
	// Scoreboard Display
	cout << "     |  " 
		<< HomeInning1.printInning()
		<< "  |  "
		<< HomeInning2.printInning()
		<< "  |  "
		<< HomeInning3.printInning()
		<< "  |  "
		<< HomeInning4.printInning()
		<< "  |  "
		<< HomeInning5.printInning()
		<< "  |  "
		<< HomeInning6.printInning()
		<< "  |  "
		<< HomeInning7.printInning()
		<< "  |  "
		<< HomeInning8.printInning()
		<< "  |  "
		<< HomeInning9.printInning()
		<< "  |Final|  H  |" << endl;
	cout << "-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|" << endl;
	cout << "  A  |  "
		<< AwayInning1.printRuns()
		<< "  |  "
		<< AwayInning2.printRuns()
		<< "  |  "
		<< AwayInning3.printRuns()
		<< "  |  "
		<< AwayInning4.printRuns()
		<< "  |  "
		<< AwayInning5.printRuns()
		<< "  |  "
		<< AwayInning6.printRuns()
		<< "  |  "
		<< AwayInning7.printRuns()
		<< "  |  "
		<< AwayInning8.printRuns()
		<< "  |  "
		<< AwayInning9.printRuns()
		<< "  |  "
		<< runtotalAway
		<< "  |  " 
		<< totalHitsAway 
		<< "  |" << endl;
	cout << "-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|" << endl;
	cout << "  H  |  "
		<< HomeInning1.printRuns()
		<< "  |  "
		<< HomeInning2.printRuns()
		<< "  |  "
		<< HomeInning3.printRuns()
		<< "  |  "
		<< HomeInning4.printRuns()
		<< "  |  "
		<< HomeInning5.printRuns()
		<< "  |  "
		<< HomeInning6.printRuns()
		<< "  |  "
		<< HomeInning7.printRuns()
		<< "  |  "
		<< HomeInning8.printRuns()
		<< "  |  "
		<< HomeInning9.printRuns()
		<< "  |  "
		<< runtotalHome
		<< "  |  " 
		<< totalHitsHome 
		<< "  |" << endl;
}
// Function Definitions
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
Inning::Inning(int i) { // keeps track of events during inning
	inning = i;
	while (printOuts() < 3) {
		cout << "What is the result of the next play in inning #" << i << ": ";
		getline(cin, userstring);
		if (userstring == "Out" || userstring == "out") {
			incrementOuts();
		}
		else if (userstring == "Hit" || userstring == "hit") {
			incrementHits();
			cout << "Did a run score? ";
			getline(cin, userstring);
			if (userstring == "yes" || userstring == "Yes") {
				int amount;
				cout << "How many?: ";
				cin >> amount;
				for (int i = 0; i < amount; i++) {
					incrementRuns();
				}
			}
		}
		else if (userstring == "Walk" || userstring == "walk") {
			cout << "Did a run score? ";
			getline(cin, userstring);
			if (userstring == "yes" || userstring == "Yes") {
				int amount;
				cout << "How many?: ";
				cin >> amount;
				for (int i = 0; i < amount; i++) {
					incrementRuns();
				}
			}
		}

	}
}