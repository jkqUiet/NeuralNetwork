#include "Reader.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string Reader::getDecode(string value)
{
    if (value == "Winter") { return  "0.25"; }
    if (value == "Spring") { return  "0.50"; }
    if (value == "Summer") { return  "0.75"; }
    if (value == "Autumn") { return  "1.0"; }
    if (value == "No Holiday") { return  "0"; }
    if (value == "Holiday") { return  "1"; }
    if (value == "Yes") { return  "0"; }
    if (value == "No") { return  "1"; }
    return value;
}

Reader::Reader()
{
}

void Reader::readCsv(string fileName, bool type)
{
    ifstream file(fileName);
    if (!file)
    {
        std::cerr << "\aError opening file.\n\n";
        exit(EXIT_FAILURE);
    }
    string buffer;
    size_t strpos = 0;
    size_t endpos;
    string token;
    string delimiter = ",";
    int iterator = 0;
    while (getline(file, buffer))
    {
        if (type) {
            data.push_back(vector<float>());
        }
        else {
            result.push_back(vector<float>());
        }
        while ((strpos = buffer.find(delimiter)) != std::string::npos) {
            token = buffer.substr(0, strpos);
            if (type) {
                data.at(iterator).push_back(stof(getDecode(token)));
            }
            else {
                result.at(iterator).push_back(stof(getDecode(token)));
            }       
            buffer.erase(0, strpos + delimiter.length());
        }
        if (type) {
            data.at(iterator).push_back(stof(getDecode(buffer)));
        }
        else {
            result.at(iterator).push_back(stof(getDecode(buffer)));
        }
        iterator++;
    }
    if (type) {
        dataReaded = true;
    }
    else {
        resultsReaded = true;
    }
}

Reader::~Reader()
{
}

std::vector<std::vector<float>>& Reader::getData()
{
    return data;
}

std::vector<vector<float>>& Reader::getResults()
{
    return result;
}

void Reader::shuffle()
{
    for (int i = 0; i < data.size(); i++) {
        int first = rand() % data.size();
        int last = rand() % data.size();
        while (first == last) {
            last = rand() % data.size();
        }
        std::swap(data.at(first), data.at(last));
        std::swap(result.at(first), result.at(last));       
    }
}
