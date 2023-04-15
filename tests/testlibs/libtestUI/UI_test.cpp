#include "UI_test.hpp"

bool test_read_step() {
  std::cout << "Running Test Read step\n";

  std::cin.clear();
  if (!std::freopen("rd_step_correct.txt", "r", stdin)) {
    test_error_code(TestError::ASSET_FILE);
    return false;
  }
    
  while (!std::cin.eof())
    if (!read_step("Test")){
      std::cout << std::endl;
      test_error_code(TestError::GET_NON_ZERO);
      return false;
    }
  
  std::fclose(stdin);

  std::cin.clear();
  if (!std::freopen("rd_step_incorrect.txt", "r", stdin)) {
    test_error_code(TestError::ASSET_FILE);
    return false;
  }
  
  while (!std::cin.eof())
    if (read_step("Test")){
      std::cout << std::endl;
      test_error_code(TestError::GET_NON_ZERO);
      return false;
    }
  
  std::cout << std::endl;
  std::fclose(stdin);
  return true;
}