#include "game_test.hpp"

void reset_field(Field test_field) {
  for (size_t i = 0; i < 9; i++)
    test_field[i] = Cell::Unused;
};

bool test_check_win_state() {
  std::cout << "Running Test Check "
            << "winner state\n";

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
    set_field((Field)f);
    if (!check_win_state()){
      test_error_code(3);
      return false;
    }
  }
  
  return true;
}

bool test_make_step() {
  std::cout << "Running Test Make step\n";

  std::srand(std::time(0U));
  Field test_field = new Cell[9]();
  reset_field(test_field);
  set_field((Field)test_field);
  
  for (size_t i = 0; i < 9; i++) {
    if (!make_step(i, Cell::X)){
      test_error_code(4);
      delete[] test_field;
      return false;
    }

    if (make_step(i, Cell::X)){
      test_error_code(5);
      delete[] test_field;
      return false;
    }
  }

  for (size_t i = 0; i < 0xFFFFULL; i++) {
    if (make_step(8 + rand() % 0xFFF8, Cell::X)){
      test_error_code(6);
      delete[] test_field;
      return false;
    }
  }
  
  delete[] test_field;
  return true;
}