#include "Game.hpp"

void run() {
  bool mode = select_mode();
  bool player = false;
  unsigned short* field = new unsigned short[9]();
  unsigned short cell_n, steps_count = 0;

  auto print = [](const unsigned short* field) {
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

    field[cell_n] = (!player ? 1 : 2);
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

bool check_win_state(const unsigned short* field) {
  for (int i = 0; i < 3; i++) // Строки
    if (field[i * 3] == field[i * 3 + 1] &&
        field[i * 3 + 1] == field[i * 3 + 2] &&
        field[i * 3] != 0)
          return true;

  for (int i = 0; i < 3; i++) // Столбцы
    if (field[i] == field[i + 3] &&
        field[i + 3] == field[i + 6] &&
        field[i] != 0)
          return true;
  
  if (field[0] == field[4] &&
      field[4] == field[8] &&
      field[0] != 0) // Главная диагональ
        return true;
  
  if (field[2] == field[4] &&
      field[4] == field[6] &&
      field[2] != 0) // Побочная диагональ
        return true;

  return false;
}

bool check_cell(const unsigned short* field,
                const unsigned short cell_number) {
  return cell_number < 9 && !field[cell_number];
}

unsigned short computer_step(const unsigned short* field) {
  std::srand(std::time(0U));

  unsigned short step;
  do
    step = rand() % 9;
  while (!check_cell(field, step));

  return step;
}