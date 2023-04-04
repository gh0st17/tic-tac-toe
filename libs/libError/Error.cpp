#include "Error.hpp"

void call_error_code(int code) {
  if (code == 1)
    print_error("Can't move here\n");
}