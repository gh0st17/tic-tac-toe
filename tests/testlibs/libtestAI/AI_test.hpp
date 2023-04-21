#include <iostream>
#include "../../../libs/libAI/AI.hpp"
#include "../../../libs/libGame/Game.hpp"
#include "../../../libs/libError/Error.hpp"

/**
* @brief Тест хода компьютером
* @details Проверка на 100000 итерациях
*          генерирования хода компьютором
*          в ячеек с индексом от 0 до 8;
*          Проверка поля без свободных ячеек
*/
bool test_computer_step();