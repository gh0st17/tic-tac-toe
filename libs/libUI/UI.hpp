#pragma once
#include <iostream>

// Вывод каждых n "клеток" через
// пробел на новой строке
// len - общая длина масива field
// Про отображение X и 0:
// Если элемент массива = 0 то выводишь просто пробел
// Если = 1 это X
// Если = 2 это 0
void print_field(const unsigned short* field,
                 unsigned n, unsigned len);

// Вывод приглашения на ввод клетки
// Что-то вроде: "Ходит name: "
void print_prompt(const char* name);

// Здесь тебе нужно чтобы пользователь
// мог выбрать режим игры:
// Если два игрока - вернуть true
// Если против компьютера - false
bool select_mode();