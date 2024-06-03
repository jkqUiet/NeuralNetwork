#pragma once
#include <vector>
#include <string>
#include <random>

class Reader
{
	std::vector<std::vector<float>> data;
	std::vector<std::vector<float>> result;
	std::string getDecode(std::string value);
public :
	Reader();
	void readCsv(std::string fileName, bool type);
	~Reader();
	std::vector<std::vector<float>>& getData();
	std::vector<std::vector<float>>& getResults();
	void shuffle();
};

