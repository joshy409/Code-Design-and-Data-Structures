#pragma once
#include "HighScoreEntry.h"
#include <fstream>
#include <vector>
#include <iostream>
class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	void bubbleSort(std::vector<HighScoreEntry>& temp);
	void insertionSort(std::vector<HighScoreEntry>& temp);
	bool pruneBottomNNScores(std::vector<HighScoreEntry>& temp, int bottomRows);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();;
};

