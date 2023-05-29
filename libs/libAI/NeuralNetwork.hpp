#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Neuron.hpp"

class NeuralNetwork {
private:
  std::vector<Neuron> hiddenLayer, hiddenLayer2, hiddenLayer3, outputLayer;
  std::vector<double> hiddenOutput, hiddenOutput2, hiddenOutput3, output;

public:
  NeuralNetwork() { };

  NeuralNetwork(const char* filename);

  std::vector<double> feedForward(const std::vector<double>& input);
};