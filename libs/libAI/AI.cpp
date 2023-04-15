#include "AI.hpp"

/** 
* @brief Анализ выбранной клетки на победу
* @param cell_number Номер клетки в поле
* @param cell_value Значение клетки
* @return true если клетка не занята
*         и в пределах поля, false - нет 
*/
bool analize_step(const unsigned short cell_number,
                  const Cell cell_value, Field field) {
  if (field[cell_number] == Cell::Unused) {
    field[cell_number] = cell_value;
    bool is_win = check_win_state();
    field[cell_number] = Cell::Unused;
    return is_win;
  }

  return false;
}

/** 
* @brief Функция для генерации хода компьютером
* @return Ход компьютера
*/
unsigned short generate_move() {
  unsigned short move = 9;
  Field field = get_field();

  // Проверяем, есть ли выигрышные ходы
  for (unsigned short i = 0; i < 9 && move > 8; ++i)
    if (analize_step(i, Cell::X, field)) // Предполагаемый ход компьютера
      move = i;

  // Если нет выигрышных ходов, блокируем ходы соперника
  if (move == 9)
    for (unsigned short i = 0; i < 9 && move > 8; ++i)
      if (analize_step(i, Cell::O, field)) // Предполагаемый ход соперника
        move = i;

  // Если нет выигрышных и блокирующих ходов, выбираем случайный ход
  if (move == 9) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned short> dist(0, 8);
    move = dist(mt);
  }

  return move;
}

unsigned short computer_step() {
  return generate_move();
}