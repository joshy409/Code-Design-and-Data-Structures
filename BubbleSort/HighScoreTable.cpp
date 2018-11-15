#include "HighScoreTable.h"



std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	std::vector<HighScoreEntry> temp;
	for (int i = 0; i < topRows; i++) {
		temp.push_back(hsVector[i]);
	}
	//bubbleSort(temp);
	insertionSort(temp);
	return temp;
}

void HighScoreTable::bubbleSort(std::vector<HighScoreEntry>& temp)
{
	for (int i = 0; i < temp.size()-1 ; i++) {
		for (int j = temp.size() - 1; j >= i + 1; j--) {
			if (temp[j].score > temp[j - 1].score) {
				HighScoreEntry tempHighScore = temp[j];
				temp[j] = temp[j - 1];
				temp[j - 1] = tempHighScore;
			}
		}
	}
}

void HighScoreTable::insertionSort(std::vector<HighScoreEntry>& temp)
{
	for (int i = 1; i < temp.size(); i++) {
		int tempInt = temp[i].score;
		HighScoreEntry tempHighScore = temp[i];
		int j = i - 1;
		while (j >= 0 && temp[j].score < tempInt) {
			temp[j + 1] = temp[j];
			j = j - 1;
		}
		temp[j + 1] = tempHighScore;
	}
}

bool HighScoreTable::pruneBottomNNScores(std::vector<HighScoreEntry>& temp, int bottomRows)
{
	for (int i = 0; i < bottomRows; i++) {
		temp.pop_back();
	}
	return false;
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	std::ifstream file(fileName, std::ios::in);
	HighScoreEntry temp;
	std::string name;
	std::string score;
	std::string level;
	while (file.good())
	{
		std::getline(file, name, ',');
		temp.name = name;

		std::getline(file, score, ',');
		temp.score = std::stoi(score);

		std::getline(file, level);
		temp.level = std::stoi(level);

		hsVector.push_back(temp);
	}
}


HighScoreTable::~HighScoreTable()
{
}
