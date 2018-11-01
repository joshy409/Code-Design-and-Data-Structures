#include "HighScoreTable.h"
#include <vector>

int main() {
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highscores.txt");

	//retrieve the top 10 scores
	std::vector<HighScoreEntry> topScores = hst.topNNScores(10);

	//todo: cycle through the scores and output them
	for (auto a : topScores) {
		std::cout << a.score << std::endl;
	}

	//prune the bottom 3 scores from the table
	hst.pruneBottomNNScores(topScores, 3);

	//retrieve the top 10 scores
	//std::vector<HighScoreEntry> topScores = hst.topNNScores(10);

	//todo: cycle through the scores and output them
	for (auto a : topScores) {
		std::cout << a.score << std::endl;
	}

	return 0;
}