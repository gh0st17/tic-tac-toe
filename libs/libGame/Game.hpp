#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "../libUI/UI.hpp"
#include "../libPlayer/Player.hpp"

// @brief Основной метод игры
void run();

/** 
* @brief Проверка выигрыша
* @param field Указатель на поле
* @return true если выигрыш, false - нет
*/
bool check_win_state(const unsigned short* field);

/** 
* @brief Проверка выбранной клетки на корректость 
* @param field Указатель на поле
* @param cell_number Номер клетки в поле
* @return true если клетка не занята
*           и в пределах поля, false - нет 
*/
bool check_cell(const unsigned short* field,
                const unsigned short cell_number);

/** 
* @brief Генерация хода компьютеом 
* @param field Указатель на поле
* @return Номер клетки
*/
unsigned short computer_step(const unsigned short* field);