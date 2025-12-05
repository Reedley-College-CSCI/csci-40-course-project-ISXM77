#ifndef GAME_H
#define GAME_H
#include <string>

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
	std::string printScoreboard() const;
	void printScoreboardToFile() const;
	void menu();
	int intRange(int lo, int hi);
	int HighScoreInning(bool side) const;
	void printHighScoreInning() const;
	void printSortedInnings(bool side) const;
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
#endif // GAME_H