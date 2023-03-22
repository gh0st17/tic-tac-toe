#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "../libUI/UI.hpp"
#include "../libPlayer/Player.hpp"

// Основной метод игры
void run();

// Тут я сделаю проверку выигрыша
bool check_win_state(char* field);

// Проверяю корректость выбранной клетки
bool check_cell();

// Уснановка в выбранную клетку
void make_step();

// Тут будет генерироваться ход компьютеом
unsigned short computer_step();
