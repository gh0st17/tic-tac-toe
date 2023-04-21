#include "../testlibs/libtestUI/UI_test.hpp"
#include "../testlibs/libtestAI/AI_test.hpp"
#include "../testlibs/libtestGame/game_test.hpp"
#include "../testlibs/libtestError/error_test.hpp"

int main() {
  bool (*tests[])() = {
    test_select_mode, test_read_step, 
    test_check_win_state, test_make_step,
    test_computer_step, test_game_error_code
  };

  for (const auto& test: tests)
    if(!test())
      return 1;

  std::cout << "All tests passed!\n";
  return 0;
}