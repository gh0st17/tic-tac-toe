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
* @brief Вывод приглашения на ввод для игрока name
* @param name Имя игрока
*/
void print_prompt(const char* name);

/**
* @brief Выбор пользователем режима игры
* @return true или false
*/
bool select_mode();