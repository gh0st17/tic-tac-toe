#include "game_test.hpp"

bool test_check_win_state() {
  std::cout << "Running Test Check "
            << "winner state\n";

  Cell fields[8][9];

  for (size_t i = 0; i < 8; i++) {
    set_field(fields[i]);
    reset_field();
  }

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

  for (const auto& field : fields) {
    set_field((Field)field);
    if (!check_win_state()){
      test_error_code(TestError::DETECT_WINNER);
      return false;
    }
  }
  
  return true;
}

bool test_make_step() {
  std::cout << "Running Test Make step\n";

  Cell test_field[9];
  set_field(test_field);
  reset_field();
  
  for (size_t i = 0; i < 9; i++) {
    if (!make_step(i, Cell::X)){
      test_error_code(TestError::CHK_EMPTY_CELL);
      return false;
    }

    if (make_step(i, Cell::X)){
      test_error_code(TestError::CHK_USED_CELL);
      return false;
    }
  }

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<unsigned short> dist(0, 0xFFF8);
  for (size_t i = 0; i < 100000; i++) {
    if (make_step(8 + dist(mt), Cell::X)){
      test_error_code(TestError::CHK_RND_CELL);
      return false;
    }
  }
  
  return true;
}