#include "Game.hpp"

void run() {
  bool mode = select_mode();
  bool player = false;
  Field field = new Cell[9]();
  unsigned short cell_n, steps_count = 0;

  auto print = [](const Field field) {
#ifdef _WIN64
    system("cls");
#else
    system("clear");
#endif
    print_field(field, 3U, 9U);
    std::cout << std::endl;
  };

  print(field);
  while (!check_win_state(field) && steps_count++ < 9U) {
    if (!mode && !player)
      cell_n = computer_step(field);
    else
      do
        print_prompt(!player ? "Player(X)" : "Player(0)");
      while (!check_cell(field, cell_n = get_number() - 1));

    field[cell_n] = (!player ? Cell::X : Cell::O);
    player = !player;

    print(field);
  }

  if (check_win_state(field))
    std::cout << (!player ? "(0)" :
      (!mode ? "Computer(X)" : "(X)")) << " win!\n";
  else if (steps_count == 10)
    std::cout << "N/A win!\n";

  delete[] field;
}

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

bool check_cell(const Field field,
                const unsigned short cell_number) {
  return cell_number < 9 && field[cell_number] == Cell::Unused;
}

unsigned short computer_step(const Field field) {
  std::srand(std::time(0U));

  unsigned short step;
  do
    step = rand() % 9;
  while (!check_cell(field, step));

  return step;
}