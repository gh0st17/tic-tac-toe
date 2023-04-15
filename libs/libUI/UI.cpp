#include "UI.hpp"

void print_manual() {
  std::cout << "The cell numbers are assigned "
            << "as follows\n";

  for (size_t i = 0; i < 9; i++) {
    std::cout << i + 1 << ' ';

    if ((i + 1) % 3 == 0)
      std::cout << std::endl;
  }

  std::cout << "\nRun program with 'AI' parameter "
            << "to start\nin AI mode or 'Player' "
            << "for two players mode\n";
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

  std::cout << std::endl;
}

unsigned short read_step(const char* name) {
  std::cout << "Player " << name << " moves: ";

  unsigned short tmp = 0;

  if (std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  if (std::cin >> tmp && tmp)
    return tmp;
  else
    return 0;
}

void print_error(const char* error_str) {
  std::cout << "An error occurred: "
            << error_str << std::endl;
}

void print_winner(const char* winner) {
  std::cout << winner << " win!\n";
}