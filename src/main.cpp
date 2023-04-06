#include <random>
#include <ctime>
#include "../libs/libAI/AI.hpp"
#include "../libs/libUI/UI.hpp"
#include "../libs/libError/Error.hpp"
#include "../libs/libGame/Game.hpp"

int main() {
  print_manual();
  bool player = false;
  std::srand(std::time(0U));
  init_field();
  unsigned short cell_n, steps_count = 0, mode = 10;
  while (mode > 9) {
    mode = select_mode();
    if (mode > 9)
      game_error_code(2);
  }

  auto print = []() {
#ifdef _WIN64
    system("cls");
#else
    system("clear");
#endif
    print_field();
  };

  print();
  while (!check_win_state() && steps_count++ < 9U) {
    if (!mode && !player)
      while (!make_step(cell_n = computer_step(), Cell::X));
    else {
      while (true) {
        cell_n = read_step(!player ? "Player(X)" : "Player(0)");
        if (!cell_n) {
          game_error_code(3);
          continue;
        }

        if (!make_step(cell_n - 1, (!player ? Cell::X : Cell::O)))
          game_error_code(1);
        else
          break;
      }
    }

    player = !player;
    print();
  }

  if (check_win_state())
    (!player ? print_winner("(0)") :
      (!mode ? print_winner("Computer(X)") :
        print_winner("(X)")));
  else
    print_winner("N/A");

  destroy_field();
  return 0;
}