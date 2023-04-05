#pragma once
#include <iostream>
#include "../libGame/Game.hpp"

/**
* @brief Вывод инструкции по вводу номера клетки
*/
void print_manual();

/**
* @brief Вывод поля на экран
*/
void print_field();

/**
* @brief Выбор пользователем режима игры
* @return true или false
*/
unsigned select_mode();

/**
* @brief Ввод клетки
* @return Номер клетки
*/
unsigned short read_step(const char* name);

/**
* @brief Вывод сообщения об ошибке
*/
void print_error(const char* error_str);
