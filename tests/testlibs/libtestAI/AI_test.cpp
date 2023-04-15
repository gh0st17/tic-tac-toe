#include "AI_test.hpp"

bool test_computer_step() {
  std::cout << "Running Test Computer step\n";

  unsigned short step;
  for (size_t i = 0; i < 100000; i++) {
    step = computer_step();
    if (step >= 9){
      test_error_code(TestError::COMPUTER_STEP);
      return false;
    }
  }

  return true;
}