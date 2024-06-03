#pragma once
#include <vector>
#include <string>
#include <random>

class Reader
{
	std::vector<std::vector<float>> data;
	std::vector<std::vector<float>> result;
	std::string getDecode(std::string value);
	bool dataReaded = false;
	bool resultsReaded = false;
public :
	Reader();
	void readCsv(std::string fileName, bool type);
	~Reader();
	std::vector<std::vector<float>>& getData();
	std::vector<std::vector<float>>& getResults();
	void shuffle();
	bool getDReaded() { return dataReaded; }
	bool getRReaded() { return resultsReaded; }
};

