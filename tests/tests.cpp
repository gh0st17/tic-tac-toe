#include "tests.hpp"

Field field;

void reset_field(Field field) {
  for (size_t i = 0; i < 9; i++)
    field[i] = Cell::Unused;
};

bool run_all_tests() {
  field = new Cell[9]();
  void (*tests[])() = {
    test_select_mode, test_get_number, 
    test_check_win_state, test_check_cell,
    test_computer_step
  };

  try {
    for (const auto& test: tests)
      test();

    std::cout << "All tests passed!\n";
    return true;
  }
  catch (std::bad_alloc const&) {
    std::cerr << "Can't allocate memory";
  }
  catch (const TestException& e) {
    std::cerr << "TestException: "
              << e.what() << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << "Exception: "
              << e.what() << std::endl;
  }

  return false;
}

void test_select_mode() {
  std::cout << "Running Test Select mode\n";

  std::istringstream iss("12\n\
2\n\
abracodabre6,\n\
77\n\n");

  size_t lines = 5;
  std::cin.rdbuf(iss.rdbuf());

  while (--lines)
    if (!select_mode())
      throw TestException("\nSelection player "
                          "mode failed");

  std::cout << std::endl;
}

void test_get_number() {
  std::cout << "Running Test Get number\n";

  std::istringstream iss("12\n\
2\n\
57abracodabre6,\n0asd\n\
77\n");

  size_t lines = 5;
  std::cin.rdbuf(iss.rdbuf());

  while (--lines)
    if (!get_number())
      throw TestException("Getting non-zero "
                          "value failed");
}

void test_check_win_state() {
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

  for (const auto& f : fields)
    if (!check_win_state((Field)f))
      throw TestException("Detecting winner "
                          "state failed");
}

void test_check_cell() {
  std::cout << "Running Test Check cell\n";

  for (size_t i = 0; i < 9; i++) {
    field[i] = Cell::X;
    if (check_cell(field, i))
      throw TestException("Check cell failed");
  }
}

void test_computer_step() {
  std::cout << "Running Test Computer step\n";

  unsigned short step;
  for (size_t i = 0; i < 100000; i++) {
    reset_field(field);
    step = computer_step(field);
    if (step > 9 || !check_cell(field, step))
      throw TestException("Computer step failed");
  }
}