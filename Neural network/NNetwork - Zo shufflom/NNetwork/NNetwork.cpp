#include <iostream>
#include <random>
#include <math.h>
#include <vector>
#include "Net.h"
#include "Reader.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Reader reader;
    reader.readCsv("SeoulBikeDataOriginalUpraveneData.csv", true);
    reader.readCsv("SeoulBikeDataOriginalUpraveneResults.csv", false);
    vector<vector<float>> data = reader.getData();
    vector<vector<float>> results = reader.getResults();
    int inputLayer = data.at(0).size();   

    vector<int> layers = {inputLayer,5, 1 };
    Net net(layers);
    net.initializeNetwork();   

    //float errrorrr = 0;
    for (int j = 0; j < 100; j++) {
        float errrorrr = 0;
        //vector<float> vec = { 0,5,0.3,0.7 };
        //vector <float> res = {0.2};
        //net.setData(vec, res);
       // net.setData(data.at(j), results.at(j));
        
        for (int i = 0; i < data.size(); i++) {
            //net.setData(data.at(i), results.at(i));
            net.setData(data.at(i), results.at(i));
            net.feedForward();
            net.backProp(0.01);   
            errrorrr += net.calculateAverageError();
        }   
        cout << (abs(errrorrr / data.size())) << endl;

        reader.shuffle();
        //net.vypis();


    }
    cout << endl;
    
}

