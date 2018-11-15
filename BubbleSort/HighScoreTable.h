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
	void mergeSortStart(std::vector<HighScoreEntry>& temp);
	void mergeSort(std::vector<HighScoreEntry>& temp, int l, int r);
	void merge(std::vector<HighScoreEntry>& temp, int l, int m, int r);
	bool pruneBottomNNScores(std::vector<HighScoreEntry>& temp, int bottomRows);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();;
};

