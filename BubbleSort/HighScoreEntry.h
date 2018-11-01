#pragma once
#include <string>
class HighScoreEntry
{
public:
	std::string name;
	int score;
	int level;
	HighScoreEntry();
	~HighScoreEntry();
};

