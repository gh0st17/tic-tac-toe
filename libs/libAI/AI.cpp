#include "AI.hpp"

unsigned short computer_step() {
  Field field = get_field();
  unsigned short step = 0, free = 0, num = 0;

  for (unsigned i = 0; i < 9; i++)
    if (field[i] == Cell::Unused)
      free++;

  if (free)
    step = rand() % free;

  for (unsigned i = 0; i < 9; i++) {
    if (field[i] == Cell::Unused)
      num++;
    if (num == step + 1)
      return i;
  }

  return 9;
}