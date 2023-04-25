#pragma once
#include "../libUI/UI.hpp"

enum class GameError {
  CANT_MOVE_HERE, INCORRECT_INPUT, COMPUTER_STEP
};

enum class TestError {
  GET_NON_ZERO,  DETECT_WINNER, CHK_EMPTY_CELL,
  CHK_USED_CELL, CHK_RND_CELL,  COMPUTER_STEP,
  FILLED_STEP, ASSET_FILE
};

/**
 * @brief Обработка кода ошибки игры
 * @param code Код ошибки
 */
void game_error_code(GameError code);

/**
 * @brief Обработка кода ошибки тестов
 * @param code Код ошибки
 */
void test_error_code(TestError code);