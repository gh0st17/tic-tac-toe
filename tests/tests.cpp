#include "tests.hpp"

Field test_field;

void reset_field(Field test_field) {
  for (size_t i = 0; i < 9; i++)
    test_field[i] = Cell::Unused;
};

bool run_all_tests() {
  test_field = new Cell[9]();
  bool (*tests[])() = {
    test_select_mode, test_read_step, 
    test_check_win_state, test_make_step,
    test_computer_step
  };

  for (const auto& test: tests)
    if(!test())
      return false;

  delete[] test_field;
  std::cout << "All tests passed!\n";
  return true;
}

bool test_select_mode() {
  std::cout << "Running Test Select mode\n";

  std::freopen("select_mode_assets.txt", "r", stdin);

  while (!std::cin.eof())
    if (!select_mode()) {
      test_error_code(1);
      return false;
    }

  std::cout << std::endl;
  std::fclose(stdin);
  return true;
}

bool test_read_step() {
  std::cout << "Running Test Read step\n";

  std::freopen("read_step_assets.txt", "r", stdin);

  while (!std::cin.eof())
    if (!read_step("Test")){
      test_error_code(2);
      return false;
    }
  
  std::fclose(stdin);
  return true;
}

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

  reset_field(test_field);
  set_field((Field)test_field);
  
  for (size_t i = 0; i < 9; i++) {
    if (!make_step(i, Cell::X)){
      test_error_code(4);
      return false;
    }

    if (make_step(i, Cell::X)){
      test_error_code(5);
      return false;
    }
  }

  std::srand(std::time(0));
  for (size_t i = 0; i < 0xFFFFULL; i++) {
    test_field[i % 8] = (rand() % 2) ?
                      Cell::X : Cell::Unused;

    if (make_step(8 + rand() % 0xFFF8, Cell::X)){
      test_error_code(6);
      return false;
    }
  }
  
  return true;
}

bool test_computer_step() {
  std::cout << "Running Test Computer step\n";

  unsigned short step;
  for (size_t i = 0; i < 100000; i++) {
    step = computer_step();
    if (step >= 9){
      test_error_code(7);
      return false;
    }
  }

  return true;
}