#include "Game.hpp"

bool check_win_state(const Field field) {
  for (int i = 0; i < 3; i++) // Строки
    if (field[i * 3] == field[i * 3 + 1] &&
        field[i * 3 + 1] == field[i * 3 + 2] &&
        field[i * 3] != Cell::Unused)
          return true;

  for (int i = 0; i < 3; i++) // Столбцы
    if (field[i] == field[i + 3] &&
        field[i + 3] == field[i + 6] &&
        field[i] != Cell::Unused)
          return true;
  
  if (field[0] == field[4] &&
      field[4] == field[8] &&
      field[0] != Cell::Unused) // Главная диагональ
        return true;
  
  if (field[2] == field[4] &&
      field[4] == field[6] &&
      field[2] != Cell::Unused) // Побочная диагональ
        return true;

  return false;
}

bool make_step(const Field field,
               const unsigned short cell_number,
               const Cell cell) {
  if (cell_number < 9 && field[cell_number] == Cell::Unused) {
    field[cell_number] = cell;
    return true;
  }
  else
    return false;
}

Field get_field() {

}