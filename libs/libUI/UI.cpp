#include "UI.hpp"

void print_field(const Field field,
                 unsigned n, unsigned len) {
  for (unsigned i = 0; i < len; i++) {
    if (field[i] == Cell::X)
      std::cout << "X ";
    else if (field[i] == Cell::O)
      std::cout << "0 ";
    else
      std::cout << "* ";

    if ((i + 1) % n == 0)
      std::cout << std::endl;
  }
}

void print_prompt(const char* name) {
  std::cout << "Player " << name << " moves: ";
}

bool select_mode() {
  char ch = 0;

  std::cout << "Enter 0 for play with computer or "
            << "any digit for play in two players mode: ";
  while (!std::isdigit(ch))
    std::cin >> ch;

  return (ch - 48);
}