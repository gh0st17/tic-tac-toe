#include "AI.hpp"

/** 
* @brief Функция для генерации хода компьютером
* @param field Игровое поле
* @return Ход компьютера
*/
unsigned short generate_move(Field field) {
  unsigned short move = 9;

  // Проверяем, есть ли выигрышные ходы
  for (unsigned short i = 0; i < 9 && move > 8; ++i)
    if (test_step(i, Cell::X)) // Предполагаемый ход компьютера
      move = i;

  // Если нет выигрышных ходов, блокируем ходы соперника
  if (move == 9)
    for (unsigned short i = 0; i < 9 && move > 8; ++i)
      if (test_step(i, Cell::O)) // Предполагаемый ход соперника
        move = i;

  // Если нет выигрышных и блокирующих ходов, выбираем случайный ход
  if (move == 9)
    move = rand() % 9;

  return move;
}

unsigned short computer_step() {
  return generate_move(get_field());
}