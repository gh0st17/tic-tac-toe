#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "../libUI/UI.hpp"
#include "../libPlayer/Player.hpp"

// Основной метод игры
void run();

// Тут я сделаю проверку выигрыша
bool check_win_state(unsigned short* field);

// Проверяю корректость выбранной клетки
bool check_cell(unsigned short cell_number);

// Уснановка в выбранную клетку
void make_step(unsigned short cell_number);

// Тут будет генерироваться ход компьютеом
unsigned short computer_step();
