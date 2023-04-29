#pragma once
#include "../libGame/Game.hpp"
#include <iostream>
#include <random>

/** 
* @brief Генерация хода компьютеом
* @return Номер клетки
*/
unsigned short computer_step();

/** 
* @brief Иницализация псевдочисел
*/
void init_AI();