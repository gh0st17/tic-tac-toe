#pragma once
#include <vector>
#include <random>
#include <cmath>

class Neuron {
private:
  std::vector<double> weights;
  double bias;

public:
  Neuron(std::vector<double> weights, double bias);

  double LeakyReLU_activate(const std::vector<double>& inputs);

  double LeakyReLU_derivative(const double out);
};