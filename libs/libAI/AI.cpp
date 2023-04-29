#include "AI.hpp"

std::random_device rd;
std::mt19937 mt;

/** 
* @brief Анализ выбранной клетки на победу
* @param cell_number Номер клетки в поле
* @param cell_value Значение клетки
* @param field Поле
* @return true - ход приведет к выигрышу,
*         false - нет
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
* @param free Количество свободных клеток
* @param field Поле
* @return Ход компьютера
*/
unsigned short generate_move(unsigned short free, Field field) {
  unsigned short move = 9;

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
    unsigned short num = 0;
    std::uniform_int_distribution<unsigned short> dist(0, free - 1);
    move = dist(mt);

    for (unsigned i = 0; i < 9; i++) {
      if (field[i] == Cell::Unused)
        num++;
      if (num == move + 1) {
        move = i;
        break;
      }
    }
  }

  return move;
}

unsigned short computer_step() {
  unsigned short free = 0;
  Field field = get_field();

  for (unsigned i = 0; i < 9; i++)
    if (field[i] == Cell::Unused)
      free++;

  if (free)
    return generate_move(free, field);
  else 
    return 9;
}

void init_AI() {
  mt = std::mt19937(rd());
}