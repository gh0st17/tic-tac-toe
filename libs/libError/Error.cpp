#include "Error.hpp"

void game_error_code(int code) {
  if (code == 1)
    print_error("Can't move here");
  else if (code == 2)
    print_error("It is not a digit");
  else if (code == 3)
    print_error("Incorrect input");
  else if (code == 4)
    print_error("No free cell");
  else
    print_error("Unknown error");
}

void test_error_code(int code) {
  if (code == 1)
    print_error("Selection player mode failed");
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
  else if (code == 8)
    print_error("Can't open assets file");
  else if (code == 9)
    print_error("Filled field failed");
  else
    print_error("Unknown error");
}