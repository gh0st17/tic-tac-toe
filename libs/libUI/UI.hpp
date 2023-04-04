#pragma once
#include <iostream>

/**
* @brief Перечисление возможных типов клетки
*/
enum class Cell { Unused, X, O };

/**
* @brief Массив ячеек (клеток) как поле
*/
typedef Cell* Field;

/**
* @brief Вывод инструкции по вводу номера клетки
*/
void print_manual();

/**
* @brief Вывод поля на экран
* @param field Указатель на поле
* @param n Ширина поля
* @param len Количество клеток в поле
*/
void print_field(const Field field,
                 unsigned n, unsigned len);

/**
* @brief Выбор пользователем режима игры
* @return true или false
*/
bool select_mode();

/**
* @brief Ввод клетки
* @return Номер клетки
*/
unsigned short read_step(const char* name);

/**
* @brief Вывод сообщения об ошибке
*/
void print_error(const char* error_str);