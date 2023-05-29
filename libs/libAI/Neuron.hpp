#pragma once
#include <vector>
#include <random>
#include <cmath>

class Neuron {
private:
  std::vector<double> weights, previousWeightUpdates;
  double bias, previousBiasUpdate,
         learningRate, momentum;

public:
  Neuron(double learningRate, double momentum, std::vector<double> weights, double bias);

  double LeakyReLU_activate(const std::vector<double>& inputs);

  double LeakyReLU_derivative(const double out);
};