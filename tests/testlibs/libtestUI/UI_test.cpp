#include "UI_test.hpp"

bool test_select_mode() {
  std::cout << "Running Test Select mode\n";

  std::cin.clear();
  if (!std::freopen("sel_mode_correct.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }

  while (std::cin.peek() != '\n')
    if (select_mode() > 9) {
      std::cout << std::endl;
      test_error_code(1);
      std::fclose(stdin);
      return false;
    }

  std::cout << std::endl;
  std::fclose(stdin);

  std::cin.clear();
  if (!std::freopen("sel_mode_incorrect.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }

  while (std::cin.peek() != '\n')
    if (select_mode() < 10) {
      std::cout << std::endl;
      test_error_code(1);
      std::fclose(stdin);
      return false;
    }

  std::cout << std::endl;
  std::fclose(stdin);
  return true;
}

bool test_read_step() {
  std::cout << "Running Test Read step\n";

  std::cin.clear();
  if (!std::freopen("rd_step_correct.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }
    
  while (!std::cin.eof())
    if (!read_step("Test")){
      std::cout << std::endl;
      test_error_code(2);
      return false;
    }
  
  std::fclose(stdin);

  std::cin.clear();
  if (!std::freopen("rd_step_incorrect.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }
  
  while (!std::cin.eof())
    if (read_step("Test")){
      std::cout << std::endl;
      test_error_code(2);
      return false;
    }
  
  std::cout << std::endl;
  std::fclose(stdin);
  return true;
}