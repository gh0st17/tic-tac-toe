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
* @brief Ввод клетки
* @param name Имя игрока
* @return Номер клетки
*/
unsigned short read_step(const char* name);

/**
* @brief Вывод сообщения об ошибке
* @param error_str Текст ошибки
*/
void print_error(const char* error_str);

/**
* @brief Вывод имени победителя
* @param winner Имя победителя
*/
void print_winner(const char* winner);