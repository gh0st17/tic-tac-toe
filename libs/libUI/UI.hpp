#pragma once
#include <iostream>

/**
* @brief Вывод поля на экран
* @param field Указатель на поле
* @param n Ширина поля
* @param len Количество клеток в поле
*/
void print_field(const unsigned short* field,
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