#pragma once
#include <iostream>
#include <random>
#include "../libGame/Game.hpp"

/** 
* @brief Генерация хода компьютеом
* @return 0-8 - Номер клетки;
*  9 - На поле нет пустых ячеек
*/
unsigned short computer_step();