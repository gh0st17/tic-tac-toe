#pragma once
#include <iostream>

// Вывод каждых n "клеток" через
// пробел на новой строке
void print_field(unsigned short* field, unsigned n);

// Вывод приглашения на ввод клетки
// Что-то вроде: "Ходит name: "
void print_prompt(const char* name);

// Здесь тебе нужно чтобы пользователь
// мог выбрать режим игры:
// Если два игрока - вернуть true
// Если против компьютера - false
bool select_mode();