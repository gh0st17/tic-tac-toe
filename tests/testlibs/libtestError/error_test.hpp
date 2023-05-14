#pragma once
#include "../../../libs/libUI/UI.hpp"
#include "../../../libs/libError/Error.hpp"

/**
* @brief Функция-счетчик вызовов печати ошибки
* @param error_str Текст ошибки
* @return Количество вызовов print_error
*/
unsigned test_print_error(const char* error_str);

/**
* @brief Функция с копией логики
*  вывода сообщения ошибки по коду
*/
bool test_game_error_code();