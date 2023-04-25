#include "Error.hpp"

void game_error_code(GameError code) {
  if (code == GameError::CANT_MOVE_HERE)
    print_error("Can't move here");
  else if (code == GameError::INCORRECT_INPUT)
    print_error("Incorrect input");
  else if (code == GameError::COMPUTER_STEP)
    print_error("Computer step failure");
  else
    print_error("Unknown error");
}

void test_error_code(TestError code) {
  if (code == TestError::GET_NON_ZERO)
    print_error("Getting non-zero value failed");
  else if (code == TestError::DETECT_WINNER)
    print_error("Detecting winner state failed");
  else if (code == TestError::CHK_EMPTY_CELL)
    print_error("Check empty cell failed");
  else if (code == TestError::CHK_USED_CELL)
    print_error("Check used cell failed");
  else if (code == TestError::CHK_RND_CELL)
    print_error("Check random cell failed");
  else if (code == TestError::COMPUTER_STEP)
    print_error("Computer step failed");
  else if (code == TestError::FILLED_STEP)
    print_error("Step in filled field failed");
  else if (code == TestError::ASSET_FILE)
    print_error("Can't open assets file");
  else
    print_error("Unknown error");
}