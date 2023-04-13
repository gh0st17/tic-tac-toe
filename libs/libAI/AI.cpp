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
    if (field[i] == Cell::Unused) {
      field[i] = Cell::X; // Предполагаемый ход компьютера

      if (check_win_state())
        move = i;

      field[i] = Cell::Unused; // Отменяем предполагаемый ход компьютера
    }

  // Если нет выигрышных ходов, блокируем ходы соперника
  if (move == 9)
    for (int i = 0; i < 9 && move > 8; ++i)
      if (field[i] == Cell::Unused) {
        field[i] = Cell::O; // Предполагаемый ход соперника
        
        if (check_win_state())
          move = i;

        field[i] = Cell::Unused; // Отменяем предполагаемый ход соперника
      }

  // Если нет выигрышных и блокирующих ходов, выбираем случайный ход
  if (move == 9)
    move = rand() % 9;

  return move;
}

unsigned short computer_step() {
  return generate_move(get_field());
}