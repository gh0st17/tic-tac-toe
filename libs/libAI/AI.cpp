#include "AI.hpp"

unsigned short computer_step() {
  Field field = get_field();
  unsigned short step = rand() % 9;

  while (field[step] != Cell::Unused)
    step = rand() % 9;

  return step;
}