#include <iostream>
#include <random>
#include <ctime>
#include "../libs/libUI/UI.hpp"
#include "../libs/libAI/AI.hpp"
#include "../libs/libGame/Game.hpp"
#include "../libs/libError/Error.hpp"

bool run_all_tests();
bool test_select_mode();
bool test_read_step();
bool test_check_win_state();
bool test_make_step();
bool test_computer_step();