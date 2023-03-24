#pragma once
#include <iostream>
#include <limits>

// Ну тут просто:
// Вводишь в переменную типа unsigned short
// и возвращаешь ее.
// Все проверки корректности ввода (то есть
// что введена имено цифра, а не буква
// или что-то еще) на тебе
unsigned short get_cell_number();
