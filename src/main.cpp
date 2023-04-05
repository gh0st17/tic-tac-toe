#include <random>
#include <ctime>
#include "../libs/libAI/AI.hpp"
#include "../libs/libUI/UI.hpp"
#include "../libs/libError/Error.hpp"
#include "../libs/libGame/Game.hpp"

int main() {
  print_manual();

  unsigned mode = 10;
  while (mode > 9) {
    mode = select_mode();
    if (mode > 9)
      call_error_code(3);
  }

  bool player = false;
  std::srand(std::time(0U));
  init_field();

  unsigned short cell_n, steps_count = 0;

  auto print = []() {
#ifdef _WIN64
    system("cls");
#else
    system("clear");
#endif
    print_field();
    std::cout << std::endl;
  };

  print();
  while (!check_win_state() && steps_count++ < 9U) {
    if (!mode && !player)
      while(!make_step(cell_n = computer_step(), Cell::X));
    else
      while(!make_step(cell_n = read_step(!player ? "Player(X)" : "Player(0)") - 1, (!player ? Cell::X : Cell::O)))
        call_error_code(1);

    player = !player;
    print();
  }

  if (check_win_state())
    std::cout << (!player ? "(0)" :
      (!mode ? "Computer(X)" : "(X)")) << " win!\n";
  else if (steps_count == 10)
    std::cout << "N/A win!\n";

  destroy_field();
  return 0;
}
