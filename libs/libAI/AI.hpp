#pragma once
#include "../libGame/Game.hpp"
#include "NeuralNetwork.hpp"
#include <iostream>
#include <vector>
#include <cmath>

/** 
* @brief Генерация хода компьютеом
* @return Номер клетки
*/
unsigned short computer_step();

/** 
* @brief Иницализация нейросети
*/
void init_AI();