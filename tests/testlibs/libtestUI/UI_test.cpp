#include "UI_test.hpp"

void close_all() {
  std::fclose(stdin);
  std::fclose(stdout);
#ifdef _WIN32
  std::freopen("CON", "a", stdout);
#else
  std::freopen("/dev/tty", "a", stdout);
#endif
}

bool test_select_mode() {
  std::cout << "Running Test Select mode\n";
  
  std::cin.clear();
  if (!std::freopen("sel_mode_correct.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }
  if (!std::freopen("sel_mode_out1.txt", "w", stdout)) {
    test_error_code(8);
    std::fclose(stdin);
    return false;
  }

  while (std::cin.peek() != '\n')
    if (select_mode() > 9) {
      std::cout << std::endl;
      test_error_code(1);
      close_all();
      return false;
    }

  std::cout << std::endl;
  close_all();

  std::cin.clear();
  std::cout.clear();
  if (!std::freopen("sel_mode_incorrect.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }
  if (!std::freopen("sel_mode_out2.txt", "w", stdout)) {
    test_error_code(8);
    std::fclose(stdin);
    return false;
  }

  while (std::cin.peek() != '\n')
    if (select_mode() < 10) {
      std::cout << std::endl;
      test_error_code(1);
      close_all();
      return false;
    }

  std::cout << std::endl;
  close_all();
  return true;
}

bool test_read_step() {
  std::cout << "Running Test Read step\n";

  std::cin.clear();
  if (!std::freopen("rd_step_correct.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }
  if (!std::freopen("rd_step_out1.txt", "w", stdout)) {
    test_error_code(8);
    std::fclose(stdin);
    return false;
  }

  while (!std::cin.eof())
    if (!read_step("Test")){
      std::cout << std::endl;
      test_error_code(2);
      return false;
    }
  
  close_all();

  std::cin.clear();
  if (!std::freopen("rd_step_incorrect.txt", "r", stdin)) {
    test_error_code(8);
    return false;
  }
  if (!std::freopen("rd_step_out2.txt", "w", stdout)) {
    test_error_code(8);
    std::fclose(stdin);
    return false;
  }
  
  while (!std::cin.eof())
    if (read_step("Test")){
      std::cout << std::endl;
      test_error_code(2);
      return false;
    }
  
  std::cout << std::endl;
  close_all();
  return true;
}