#include "AI.hpp"

NeuralNetwork nw;

const std::vector<double> field_to_vec(Field field, unsigned short& free) {
  std::vector<double> vec_field;

  for (size_t i = 0; i < 9; i++)
    if (field[i] == Cell::X)
      vec_field.push_back(1.0);
    else if (field[i] == Cell::O)
      vec_field.push_back(2.0);
    else {
      vec_field.push_back(0.0);
      free++;
    }

  return vec_field;
}

unsigned short computer_step() {
  unsigned short free = 0, step;
  auto field = field_to_vec(get_field(), free);

  if (!free)
    return 9;

  double raw_step = std::abs(nw.feedForward(field)[0]);
  step = std::round(raw_step);

  if (field[step] != 0.0)
    step = std::ceil(raw_step);
  else
    return step;

  if (field[step] != 0.0)
    step = std::floor(raw_step);
  else
    return step;

  if (field[step] != 0.0)
    return 10;
  else
    return step;
}

void init_AI() {
  nw = NeuralNetwork("layers.dat");
}