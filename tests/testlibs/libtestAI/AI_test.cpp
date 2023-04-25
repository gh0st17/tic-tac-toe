#include "AI_test.hpp"

bool test_computer_step() {
  std::cout << "Running Test Computer step\n";

  Cell test_field[9];
  set_field((Field)test_field);
  reset_field();

  unsigned short step;
  for (size_t i = 0; i < 100000; i++) {
    if ((i + 1) % 9 == 0)
      reset_field();

    step = computer_step();
    if (step >= 9) {
      test_error_code(TestError::COMPUTER_STEP);
      return false;
    }

    test_field[step] = Cell::X;
  }

  for (size_t i = 0; i < 9; i++)
    test_field[i] = Cell::O;

  if (computer_step() != 9) {
    test_error_code(TestError::FILLED_STEP);
    return false;
  }

  return true;
}