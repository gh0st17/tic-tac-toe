#pragma once
#include <iostream>
#include "../libAI/AI.hpp"
#include "../libUI/UI.hpp"

/** 
* @brief Проверка выигрыша
* @param field Указатель на поле
* @return true если выигрыш, false - нет
*/
bool check_win_state(const Field field);

/** 
* @brief Проверка выбранной клетки на корректость
* @param field Указатель на поле
* @param cell_number Номер клетки в поле
* @param cell Новое значение клетки
* @return true если клетка не занята
*         и в пределах поля, false - нет 
*/
bool make_step(const Field field,
               const unsigned short cell_number,
               const Cell cell);

/** 
* @brief Возвращает поле
* @return Поле
*/
Field get_field();