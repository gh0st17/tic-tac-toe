#include "Game.hpp"

void run() {
  bool mode = select_mode();
  bool player = false;
  unsigned short* field = new unsigned short[9]();
  unsigned short cell_n, steps_count = 0;

  while (!check_win_state(field) && steps_count++ < 9U) {
    print_field(field, 3U, 9U);
    std::cout << std::endl;

    if (!mode && !player)
      cell_n = computer_step();
    else
      do
        print_prompt(!player ? "Player(X)" : "Player(0)");
      while (!check_cell(cell_n = get_cell_number()));

#ifdef _WIN64
      system("cls");
#else
      system("clear");
#endif

    make_step(cell_n);
    player = !player;
  }

  std::cout << (!player ? "Player(0)" :
    (mode ? "Computer" : "Player(X)")) << " win!\n";

  delete[] field;
}