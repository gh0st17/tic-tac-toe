#include <iostream>
#include <sstream>
#include <random>
#include <ctime>
#include "test_exception.hpp"
#include "../libs/libUI/UI.hpp"
#include "../libs/libGame/Game.hpp"
#include "../libs/libPlayer/Player.hpp"

bool run_all_tests();
void test_select_mode();
void test_get_number();
void test_check_win_state();
void test_check_cell();
void test_computer_step();