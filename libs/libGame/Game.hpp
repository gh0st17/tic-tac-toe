#pragma once
#include <iostream>
#include "../libUI/UI.hpp"
#include "../libAI/AI.hpp"

/**
* @brief Перечисление возможных типов клетки
*/
enum class Cell { Unused, X, O };

/**
* @brief Массив ячеек (клеток) как поле
*/
typedef Cell* Field;

/** 
* @brief Проверка выигрыша
* @return true если выигрыш, false - нет
*/
bool check_win_state();

/** 
* @brief Проверка выбранной клетки на корректость
* @param cell_number Номер клетки в поле
* @param cell_value Новое значение клетки
* @return true если клетка не занята
*         и в пределах поля, false - нет 
*/
bool make_step(const unsigned short cell_number,
               const Cell cell_value);

/** 
* @brief Устанавливает поле
*/
void set_field(Field new_field);

/** 
* @brief Возвращает поле
* @return Поле
*/
Field get_field();

/** 
* @brief Создает поле
*/
void init_field();

/** 
* @brief Удаляет поле
*/
void destroy_field();