#include "AI.hpp"

unsigned short computer_step() {
  std::srand(std::time(0U));
  return rand() % 9;
}