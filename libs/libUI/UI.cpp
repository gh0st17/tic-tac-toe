#include "UI.hpp"

void print_field(const unsigned short* field,
                 unsigned n, unsigned len) {
  for (unsigned i = 0; i < len; i++) {
    if (field[i] == 0)
      std::cout << "* ";
    else if (field[i] == 1)
      std::cout << "X ";
    else if (field[i] == 2)
      std::cout << "0 ";

    if ((i + 1) % n == 0)
      std::cout << std::endl;
  }
}

void print_prompt(const char* name) {
  std::cout << "Player " << name << " moves: ";
}

bool select_mode() {
  bool mode;
  char ch = 'a';

  std::cout << "Enter 0 for play with computer or "
            << "1 for play in two players mode: ";
  while(std::isdigit(ch = std::getchar()));

  return (ch - 48);
}