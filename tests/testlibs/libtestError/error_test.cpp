#include "error_test.hpp"

unsigned test_print_error(const char* error_str) {
  static unsigned counter = 0;

  print_error(error_str);
  counter++;

  return counter;
}

bool test_game_error_code() {
  std::cout << "Running Test Error code\n";

  unsigned max_error_code = 4, counter;

  const char* messages[5] = {
    "Can't move here", "It is not a digit",
    "Incorrect input","No free cell",
    "Unknown error"
  };

  for (unsigned i = 1; i <= max_error_code + 1; i++)
    counter = test_print_error(messages[i - 1]);

  return counter == max_error_code + 1;
}