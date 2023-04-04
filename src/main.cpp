#include "../libs/libAI/AI.hpp"
#include "../libs/libUI/UI.hpp"
#include "../libs/libError/Error.hpp"
#include "../libs/libGame/Game.hpp"

int main() {
  print_manual();
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
      while(!make_step(field, cell_n = computer_step(), Cell::X));
    else
      while(!make_step(field, cell_n = read_step(!player ? "Player(X)" : "Player(0)") - 1, (!player ? Cell::X : Cell::O)))
        call_error_code(1);

    player = !player;
    print(field);
  }

  if (check_win_state(field))
    std::cout << (!player ? "(0)" :
      (!mode ? "Computer(X)" : "(X)")) << " win!\n";
  else if (steps_count == 10)
    std::cout << "N/A win!\n";

  delete[] field;

  return 0;
}