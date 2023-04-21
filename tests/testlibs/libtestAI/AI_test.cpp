#include "AI_test.hpp"

bool test_computer_step() {
  std::cout << "Running Test Computer step\n";

  unsigned short step;

  Cell field[9];
  for (auto& cell : field)
    cell = Cell::Unused;

  set_field(field);

  for (size_t i = 0; i < 100000; i++) {
    if (i % 9 == 0)
      for (auto& cell : field)
        cell = Cell::Unused;

    step = computer_step();
    if (step >= 9) {
      test_error_code(7);
      return false;
    }

    field[step] = Cell::X;
  }

  for (auto& cell : field)
    cell = Cell::O;

  if (computer_step() != 9) {
    test_error_code(9);
    return false;
  }

  return true;
}