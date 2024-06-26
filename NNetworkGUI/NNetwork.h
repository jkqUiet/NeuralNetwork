#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <math.h>

using namespace std;

class NNetwork
{
    vector<vector<float>> biases; // nulta vrstva inputy, posledna outputy
    vector<vector<float>> deltas; // posledna outputy
    vector<vector<float>> activations;
    vector<vector<float>> zCalculated;
    vector<float> estimatedResult;

    vector<vector<vector<float>>> weights; // 1.vec = vrstvy, 2.vec = vyska vrstvy, 3. odkazujuce sa vahy na dalsiu vrstvu 
    vector<vector<vector<float>>> nablas; // rovnako ako pri weights

    vector<float> errors; // velkost outputov
    vector<int> layers; // poradie 0 - pocet inputov, 1 - ... pocet vyska vrstvy v poradi, posledny pocet outputov 


public:
    NNetwork(vector<int> vlayers);
    //void vypis();
    float calculateSumError();
    void backProp(float learningRate);
    void initializeNNetworkwork();
    float sigmaFunction(float z);
    float derivatedSigmoid(float z);
    float calculateError(float y, float yEstimated);
    void feedForward();
    void setData(vector<float>& data, vector<float>& estimated);
    vector<vector<float>>& getActivations();
    vector<vector<vector<float>>>& getWeights();
    ~NNetwork();
};

NNetwork::~NNetwork() {}

NNetwork::NNetwork(vector<int> vlayers) {
    layers = vlayers;
}

/*inline void NNetwork::vypis() {
    cout << "Delty" << end;
    for (int i = 0; i < biases.size(); i++) {
        for (int j = 0; j < biases.at(i).size(); j++) {
            cout << deltas.at(i).at(j) << "  ";
        }
        cout << endl;
    }
}*/

inline float NNetwork::sigmaFunction(float z) {
    return 1.0 / (1.0 + exp(-z));
}

inline float NNetwork::derivatedSigmoid(float z) {
    return sigmaFunction(z) * (1 - sigmaFunction(z));
}

inline float NNetwork::calculateError(float y, float yEstimated) {
    return yEstimated - y;
}

inline void NNetwork::feedForward() {
    for (int i = 0; i < biases.size() - 1; i++) {
        for (int j = 0; j < biases.at(i + 1).size(); j++) {
            float varSum = 0;
            for (int b = 0; b < biases.at(i).size(); b++) {
                varSum += activations.at(i).at(b) * weights.at(i).at(b).at(j);
            }
            varSum += biases.at(i + 1).at(j);
            //activations.at(i + 1).at(j) = varSum * (1 - varSum);
            activations.at(i + 1).at(j) = sigmaFunction(varSum);
            zCalculated.at(i + 1).at(j) = varSum;
        }
    }
}

inline void NNetwork::setData(vector<float>& data, vector<float>& estimated) {
    activations.at(0) = data;
    estimatedResult = estimated;
}

inline vector<vector<float>>& NNetwork::getActivations()
{
    return activations;
}

inline vector<vector<vector<float>>>& NNetwork::getWeights()
{
    return weights;
}

inline void NNetwork::initializeNNetworkwork() {

    for (int i = 0; i < layers.size(); i++) {
        biases.push_back(vector<float>());
        activations.push_back(vector<float>());
        zCalculated.push_back(vector<float>());
        deltas.push_back(vector<float>());
        for (int j = 0; j < layers.at(i); j++) {
            float vGen = ((double)rand() / (RAND_MAX));
            biases.at(i).push_back(vGen);
            activations.at(i).push_back(0);
            zCalculated.at(i).push_back(0);
            deltas.at(i).push_back(0);
        }
    }

    for (int i = 0; i < layers.size() - 1; i++) {
        weights.push_back(vector<vector<float>>());
        nablas.push_back(vector<vector<float>>());
        for (int k = 0; k < layers.at(i); k++) {
            weights.at(i).push_back(vector<float>());
            nablas.at(i).push_back(vector<float>());
            for (int j = 0; j < layers.at(i + 1); j++) {
                weights.at(i).at(k).push_back(((double)rand() / (RAND_MAX)));
                nablas.at(i).at(k).push_back(0);
            }
        }
    }
}

inline void NNetwork::backProp(float learningRate) {

    for (int i = 0; i < biases.at(layers.size() - 1).size(); i++) {
        errors.push_back(calculateError(activations.at(layers.size() - 1).at(i), estimatedResult.at(i))); 
        deltas.at(layers.size() - 1).at(i) = errors.at(i) * derivatedSigmoid(zCalculated.at(layers.size() - 1).at(i));
        for (int j = 0; j < biases.at(layers.size() - 2).size(); j++) {
            nablas.at(layers.size() - 2).at(j).at(i) = deltas.at(layers.size() - 1).at(i) * activations.at(layers.size() - 2).at(j);
        }
    }

    for (int i = layers.size() - 2; i > 0; i--) {
        for (int j = 0; j < biases.at(i).size(); j++) {
            float varSum = 0;
            for (int k = 0; k < biases.at(i + 1).size(); k++) {
                varSum += deltas.at(i + 1).at(k) * weights.at(i).at(j).at(k);
            }
            varSum *= derivatedSigmoid(zCalculated.at(i).at(j));
            deltas.at(i).at(j) = varSum;
        }
    }

    for (int i = layers.size() - 2; i > 0; i--) {
        for (int j = 0; j < biases.at(i).size(); j++) {
            for (int k = 0; k < biases.at(i - 1).size(); k++) {
                nablas.at(i - 1).at(k).at(j) = activations.at(i - 1).at(k) * deltas.at(i).at(j);
            }
        }
    }

    for (int i = 1; i < layers.size(); i++) {
        for (int j = 0; j < biases.at(i).size(); j++) {
            biases.at(i).at(j) += (learningRate * deltas.at(i).at(j));
            for (int k = 0; k < biases.at(i - 1).size(); k++) {
                weights.at(i - 1).at(k).at(j) += (learningRate * nablas.at(i - 1).at(k).at(j));
            }
        }
    }
}

inline float NNetwork::NNetwork::calculateSumError() {
    float sum = 0;
    for (auto e : errors) {
        sum += pow(e,2); 
    }
    errors.clear();
    return sum;
}
