#include "Error.hpp"

void call_error_code(int code) {
  char* msg;

  if (code == 1)
    msg = "Can't move here";
  else if (code == 2)
    msg = "It is not a digit";
  else
    msg = "Unknown error";

  print_error(msg);
}