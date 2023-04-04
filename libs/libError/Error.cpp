#include "Error.hpp"

void call_error_code(int code) {
  if (code == 1)
    print_error("Can't move here");
  else if (code == 2)
    print_error("Wrong number");
  else if (code == 3)
    print_error("It is not a digit");
  else
    print_error("Unknown error");
}