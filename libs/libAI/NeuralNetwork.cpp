#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(const char* filename) {
  std::ifstream ifs(filename, std::fstream::binary);
  if (!ifs) {
    std::cerr << "Can't open layers data file\n";
    exit(1);
  }

  size_t hiddenLayers;

  double weight, bias, learningRate, momentum;

  ifs.read(reinterpret_cast<char*>(&learningRate), sizeof(double));
  ifs.read(reinterpret_cast<char*>(&momentum), sizeof(double));
  ifs.read(reinterpret_cast<char*>(&hiddenLayers), sizeof(size_t));

  hiddenOutput.resize(hiddenLayers);
  hiddenOutput2.resize(hiddenLayers);
  hiddenOutput3.resize(hiddenLayers);
  output.resize(1U);

  std::vector<double> weights(9U);

  for (size_t n = 0; n < hiddenLayers; n++) {
    for (size_t w = 0; w < 9U; w++) {
      ifs.read(reinterpret_cast<char*>(&weight), sizeof(double));
      weights[w] = weight;
    }

    ifs.read(reinterpret_cast<char*>(&bias), sizeof(double));
    hiddenLayer.push_back(Neuron(learningRate, momentum, weights, bias));
  }

  weights.resize(hiddenLayers);
  for (size_t n = 0; n < hiddenLayers; n++) {
    for (size_t w = 0; w < hiddenLayers; w++) {
      ifs.read(reinterpret_cast<char*>(&weight), sizeof(double));
      weights[w] = weight;
    }

    ifs.read(reinterpret_cast<char*>(&bias), sizeof(double));
    hiddenLayer2.push_back(Neuron(learningRate, momentum, weights, bias));
  }

  for (size_t n = 0; n < hiddenLayers; n++) {
    for (size_t w = 0; w < hiddenLayers; w++) {
      ifs.read(reinterpret_cast<char*>(&weight), sizeof(double));
      weights[w] = weight;
    }

    ifs.read(reinterpret_cast<char*>(&bias), sizeof(double));
    hiddenLayer3.push_back(Neuron(learningRate, momentum, weights, bias));
  }

  for (size_t n = 0; n < 1U; n++) {
    for (size_t w = 0; w < hiddenLayers; w++) {
      ifs.read(reinterpret_cast<char*>(&weight), sizeof(double));
      weights[w] = weight;
    }

    ifs.read(reinterpret_cast<char*>(&bias), sizeof(double));
    outputLayer.push_back(Neuron(learningRate, momentum, weights, bias));
  }

  ifs.close();
}

std::vector<double> NeuralNetwork::feedForward(const std::vector<double>& input) {
  // Проход перед через скрытый слой 1
  for (size_t i = 0; i < hiddenLayer.size(); ++i)
    hiddenOutput[i] = hiddenLayer[i].LeakyReLU_activate(input);

  // Проход перед через скрытый слой 2
  for (size_t i = 0; i < hiddenLayer2.size(); ++i)
    hiddenOutput2[i] = hiddenLayer2[i].LeakyReLU_activate(hiddenOutput);

  // Проход перед через скрытый слой 3
  for (size_t i = 0; i < hiddenLayer3.size(); ++i)
    hiddenOutput3[i] = hiddenLayer3[i].LeakyReLU_activate(hiddenOutput2);

  // Проход перед через выходной слой
  for (size_t i = 0; i < outputLayer.size(); ++i)
    output[i] = outputLayer[i].LeakyReLU_activate(hiddenOutput3);

  return output;
}
