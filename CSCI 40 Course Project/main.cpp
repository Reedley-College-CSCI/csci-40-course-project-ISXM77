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

class Stats { // class holding stats to be tracked 
public:
	int inning = 1;
	int outs = 0;
	int hits = 0;
	int runs = 0;
};
class Home { // class for Home team's half inning
public:
	Home(int i);
	Stats homestats[10];
};
class Away { // class for Away team's half inning
public:
	Away(int i);
	Stats awaystats[10];
};

int main() {

	Away Away1(1); // 9 Home and 9 Away half innings
	Home Home1(1);
	Away Away2(2);
	Home Home2(2);
	Away Away3(3);
	Home Home3(3);
	Away Away4(4);
	Home Home4(4);
	Away Away5(5);
	Home Home5(5);
	Away Away6(6);
	Home Home6(6);
	Away Away7(7);
	Home Home7(7);
	Away Away8(8);
	Home Home8(8);
	Away Away9(9);
	Home Home9(9);

	int totalrunsaway = // totals runs scored for away team
		Away1.awaystats[1].runs + 
		Away2.awaystats[2].runs +
		Away3.awaystats[3].runs +
		Away4.awaystats[4].runs +
		Away5.awaystats[5].runs +
		Away6.awaystats[6].runs +
		Away7.awaystats[7].runs +
		Away8.awaystats[8].runs +
		Away9.awaystats[9].runs;

	int totalrunshome = // totals runs scored for home team
		Home1.homestats[1].runs + 
		Home2.homestats[2].runs +
		Home3.homestats[3].runs +
		Home4.homestats[4].runs +
		Home5.homestats[5].runs +
		Home6.homestats[6].runs +
		Home7.homestats[7].runs +
		Home8.homestats[8].runs +
		Home9.homestats[9].runs;

	int totalhitsaway = // totals hits for away team
		Away1.awaystats[1].hits + 
		Away2.awaystats[2].hits +
		Away3.awaystats[3].hits +
		Away4.awaystats[4].hits +
		Away5.awaystats[5].hits +
		Away6.awaystats[6].hits +
		Away7.awaystats[7].hits +
		Away8.awaystats[8].hits +
		Away9.awaystats[9].hits;

	int totalhitshome = // totals hits for home team
		Home1.homestats[1].hits +
		Home2.homestats[2].hits +
		Home3.homestats[3].hits +
		Home4.homestats[4].hits +
		Home5.homestats[5].hits +
		Home6.homestats[6].hits +
		Home7.homestats[7].hits +
		Home8.homestats[8].hits +
		Home9.homestats[9].hits;

	cout << endl;

	// Scoreboard output
	cout << "     |  "
		<< Home1.homestats[1].inning
		<< "  |  "
		<< Home2.homestats[2].inning
		<< "  |  "
		<< Home3.homestats[3].inning
		<< "  |  "
		<< Home4.homestats[4].inning
		<< "  |  "
		<< Home5.homestats[5].inning
		<< "  |  "
		<< Home6.homestats[6].inning
		<< "  |  "
		<< Home7.homestats[7].inning
		<< "  |  "
		<< Home8.homestats[8].inning
		<< "  |  "
		<< Home9.homestats[9].inning
		<< "  |  R  |  H  |" << endl;
	cout << "-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|" << endl;
	cout << "  A  |  "
		<< Away1.awaystats[1].runs
		<< "  |  "
		<< Away2.awaystats[2].runs
		<< "  |  "
		<< Away3.awaystats[3].runs
		<< "  |  "
		<< Away4.awaystats[4].runs
		<< "  |  "
		<< Away5.awaystats[5].runs
		<< "  |  "
		<< Away6.awaystats[6].runs
		<< "  |  "
		<< Away7.awaystats[7].runs
		<< "  |  "
		<< Away8.awaystats[8].runs
		<< "  |  "
		<< Away9.awaystats[9].runs
		<< "  |  "
		<< totalrunsaway
		<< "  |  "
		<< totalhitsaway
		<< "  |" << endl;
	cout << "-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|" << endl;
	cout << "  H  |  "
		<< Home1.homestats[1].runs
		<< "  |  "
		<< Home2.homestats[2].runs
		<< "  |  "
		<< Home3.homestats[3].runs
		<< "  |  "
		<< Home4.homestats[4].runs
		<< "  |  "
		<< Home5.homestats[5].runs
		<< "  |  "
		<< Home6.homestats[6].runs
		<< "  |  "
		<< Home7.homestats[7].runs
		<< "  |  "
		<< Home8.homestats[8].runs
		<< "  |  "
		<< Home9.homestats[9].runs
		<< "  |  "
		<< totalrunshome
		<< "  |  "
		<< totalhitshome
		<< "  |" << endl;


	return 0;
}
Home::Home(int i) { // constructor for Home half inning
	homestats[i].inning = i;
	string userstring;
	while (homestats[i].outs != 3) {
		cout << "What is the result of the next play in the bottom of inning #" << i << ": ";
		getline(cin, userstring);
		if (userstring == "out" || userstring == "Out") {
			homestats[i].outs += 1;
		}
		else if (userstring == "hit" || userstring == "Hit") {
			int count;
			homestats[i].hits += 1;
			cout << "Runs Scored: ";
			cin >> count;
			while (count > 4) {
				cout << "Too many, Try Again: ";
				cin >> count;
			}
			for (int i = 0; i < count; i++) {
				homestats[i].runs += 1;
			}
		}
		else if (userstring == "walk" || userstring == "Walk") {
			int count;
			cout << "Runs Scored: ";
			cin >> count;
			while (count > 2) {
				cout << "Too many, Try Again: ";
				cin >> count;
			}
			for (int i = 0; i < count; i++) {
				homestats[i].runs += 1;
			}

		}
	}
}
Away::Away(int i) { // constructor for away half inning
	awaystats[i].inning = i;
	string userstring;
	while (awaystats[i].outs != 3) {
		cout << "What is the result of the next play in the top of inning #" << i << ": ";
		getline(cin, userstring);
		if (userstring == "out" || userstring == "Out") {
			awaystats[i].outs += 1;
		}
		else if (userstring == "hit" || userstring == "Hit") {
			int count;
			awaystats[i].hits += 1;
			cout << "Runs Scored: ";
			cin >> count;
			while (count > 4) {
				cout << "Too many, Try Again: ";
				cin >> count;
			}
			for (int i = 0; i < count; i++) {
				awaystats[i].runs += 1;
			}
		}
		else if (userstring == "walk" || userstring == "Walk") {
			int count;
			cout << "Runs Scored: ";
			cin >> count;
			while (count > 2) {
				cout << "Too many, Try Again: ";
				cin >> count;
			}
			for (int i = 0; i < count; i++) {
				awaystats[i].runs += 1;
			}

		}
	}
}