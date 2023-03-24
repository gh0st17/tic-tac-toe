#include "tests.hpp"

unsigned short* field;

bool run_all_tests() {
  field = new unsigned short[9]();
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
  
  unsigned short fields[8][9] = {
    { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
    { 1, 0, 0, 1, 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 1, 0, 0 }
  };

  for (const auto& f : fields) {
    if (!check_win_state(f)) {
      std::cout << "Detecting winner state failed\n";
      return false;
    }
  }

  return true;
}

bool test_check_cell() {
  std::cout << "Running Test Check cell\n";

  for (size_t i = 0; i < 9; i++) {
    field[i] = 1;
    if (check_cell(field, i)) {
      std::cout << "Check cell failed\n";
      return false;
    }
  }  

  return true;
}

bool test_computer_step() {
  std::cout << "Running Test Computer step\n";
  
  auto reset_field = []() {
    for (size_t i = 0; i < 9; i++)
      field[i] = 0;
  };

  unsigned short step;
  for (size_t i = 0; i < 100000; i++) {
    reset_field();
    step = computer_step(field);
    if (step > 9 || !check_cell(field, step)) {
      std::cout << "Computer step failed\n";
      return false;
    }
  }

  return true;
}