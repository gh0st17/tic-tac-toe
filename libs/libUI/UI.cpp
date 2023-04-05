#include "UI.hpp"

void print_manual() {
  std::cout << "The cell numbers are assigned "
            << "as follows\n";

  for (size_t i = 0; i < 9; i++) {
    std::cout << i + 1 << ' ';

    if ((i + 1) % 3 == 0)
      std::cout << std::endl;
  }
}

void print_field() {
  Field field = get_field();
  for (unsigned i = 0; i < 9; i++) {
    if (field[i] == Cell::X)
      std::cout << "X ";
    else if (field[i] == Cell::O)
      std::cout << "0 ";
    else
      std::cout << "* ";

    if ((i + 1) % 3 == 0)
      std::cout << std::endl;
  }
}

unsigned select_mode() {
  char ch = 0;

  std::cout << "Enter 0 for play with computer or "
            << "any digit for play in two players mode: ";
  std::cin >> ch;
  if (!std::isdigit(ch))
    return 10;
  else
    return (ch - 48);
}

unsigned short read_step(const char* name) {
  std::cout << "Player " << name << " moves: ";

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

void print_error(const char* error_str) {
  std::cout << "An error occured: "
            << error_str << std::endl;
}