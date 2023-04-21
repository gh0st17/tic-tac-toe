#include "AI.hpp"

short computer_step() {
  Field field = get_field();
  unsigned short step, free = 0, num = 0;

  for (unsigned i = 0; i < 9; i++)
    if (field[i] == Cell::Unused) {
      free++;
    }

  step = rand() % free;

  for (unsigned i = 0; i < 9; i++) {
    if (field[i] == Cell::Unused)
      num++;
    if (num == step + 1)
      return i;
  }

  return -1;
}