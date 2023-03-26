#include "tests.hpp"
#include <sys/_types/_size_t.h>

Field field;

void reset_field(Field field) {
  for (size_t i = 0; i < 9; i++)
    field[i] = Cell::Unused;
};

bool run_all_tests() {
  field = new Cell[9]();
  bool (*tests[])() = {
    test_check_win_state, test_check_cell,
    test_computer_step
  };

  for (const auto& test: tests)
    if (!test()) 
      return false;

  std::cout << "All tests passed!\n";
  return true;
}

bool test_check_win_state() {
  std::cout << "Running Test Check winner state\n";

  Cell fields[8][9];

  for (size_t i = 0; i < 8; i++)
    reset_field(fields[i]);

  for (size_t i = 0; i < 3; i++)
    for (size_t j = 0; j < 3; j++)
      fields[i][i * 3 + j] = Cell::X;

  for (size_t i = 3; i < 6; i++)
    for (size_t j = 0; j < 3; j++)
      fields[i][(i - 3) + j * 3] = Cell::X;

  fields[6][0] = fields[6][4] =
    fields[6][8] = Cell::X;

  fields[7][2] = fields[7][4] =
    fields[7][6] = Cell::X;

  for (const auto& f : fields) {
    if (!check_win_state((Field)f)) {
      std::cout << "Detecting winner state failed\n";
      return false;
    }
  }

  return true;
}

bool test_check_cell() {
  std::cout << "Running Test Check cell\n";

  for (size_t i = 0; i < 9; i++) {
    field[i] = Cell::X;
    if (check_cell(field, i)) {
      std::cout << "Check cell failed\n";
      return false;
    }
  }  

  return true;
}

bool test_computer_step() {
  std::cout << "Running Test Computer step\n";

  unsigned short step;
  for (size_t i = 0; i < 100000; i++) {
    reset_field(field);
    step = computer_step(field);
    if (step > 9 || !check_cell(field, step)) {
      std::cout << "Computer step failed\n";
      return false;
    }
  }

  return true;
}