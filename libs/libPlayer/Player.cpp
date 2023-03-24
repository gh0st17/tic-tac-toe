#include "Player.hpp"

unsigned short get_cell_number() {
  auto clear = []() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  };

  unsigned short tmp = 0;
  while (true) {
    if (std::cin >> tmp && tmp > 0)
      break;
    else
      clear();
  }
  clear();
  return tmp;
}