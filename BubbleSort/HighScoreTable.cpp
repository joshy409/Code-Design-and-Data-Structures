#include "HighScoreTable.h"



std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	std::vector<HighScoreEntry> temp;
	for (int i = 0; i < topRows; i++) {
		temp.push_back(hsVector[i]);
	}
	//bubbleSort(temp);
	//insertionSort(temp);
	mergeSortStart(temp);
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

void HighScoreTable::mergeSortStart(std::vector<HighScoreEntry>& temp)
{
	mergeSort(temp, 0, temp.size() - 1);
}

void HighScoreTable::mergeSort(std::vector<HighScoreEntry>& temp, int l, int r)
{

	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(temp, l, m);
		mergeSort(temp, m + 1, r);

		merge(temp, l, m, r);
	}
}

void HighScoreTable::merge(std::vector<HighScoreEntry>& temp, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	std::vector<HighScoreEntry> L(n1);
	std::vector<HighScoreEntry> R(n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) {
		L[i] = temp[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = temp[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i].score >= R[j].score)
		{
			temp[k] = L[i];
			i++;
		}
		else
		{
			temp[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		temp[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		temp[k] = R[j];
		j++;
		k++;
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
