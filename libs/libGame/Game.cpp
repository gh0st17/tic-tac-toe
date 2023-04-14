#include "Game.hpp"

Field field;

bool check_win_state() {
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

bool make_step(const unsigned short cell_number,
               const Cell cell_value) {
  if (cell_number < 9 && field[cell_number] == Cell::Unused) {
    field[cell_number] = cell_value;
    return true;
  }
  else
    return false;
}

void set_field(Field new_field) {
  field = new_field;
}

Field get_field() {
  return field;
}

void init_field() {
  field = new Cell[9]();
}

void destroy_field() {
  if (field)
    delete[] field;
}