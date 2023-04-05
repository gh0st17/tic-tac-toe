#include "Error.hpp"

void game_error_code(int code) {
  if (code == 1)
    print_error("Can't move here");
  else if (code == 2)
    print_error("It is not a digit");
  else
    print_error("Unknown error");
}

void test_error_code(int code) {
  if (code == 1)
    print_error("\nSelection player mode failed");
  else if (code == 2)
    print_error("Getting non-zero value failed");
  else if (code == 3)
    print_error("Detecting winner state failed");
  else if (code == 4)
    print_error("Check empty cell failed");
  else if (code == 5)
    print_error("Check used cell failed");
  else if (code == 6)
    print_error("Check random cell failed");
  else if (code == 7)
    print_error("Computer step failed");
  else
    print_error("Unknown error");
}