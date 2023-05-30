#include "Neuron.hpp"

Neuron::Neuron(std::vector<double> weights, double bias) {
  // Инициализация весов
  this->weights = weights;

  // Инициализация смещения
  this->bias = bias;
}

double Neuron::LeakyReLU_activate(const std::vector<double>& inputs) {
  double weightedSum = 0.0;
  for (size_t i = 0; i < inputs.size(); ++i) {
    weightedSum += inputs[i] * weights[i];
  }
  weightedSum += bias;

  return (weightedSum < 0.0 ? 0.01 * weightedSum : (weightedSum > 8.0 ? 8.0 : weightedSum));
}

double Neuron::LeakyReLU_derivative(const double out) {
  return (out < 0 ? 0.01 : 1.0);
}