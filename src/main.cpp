#include <random>
#include "../libs/libAI/AI.hpp"
#include "../libs/libUI/UI.hpp"
#include "../libs/libError/Error.hpp"
#include "../libs/libGame/Game.hpp"

void run(bool mode);

int main(int argc, const char* argv[]) {
  if (argc > 1) {
    if (std::string(argv[1]) == "AI")
      run(false);
    else if (std::string(argv[1]) == "Player")
      run(true);
    else
      print_manual();
  }
  else
    print_manual();
  return 0;
}

void run(bool mode) {
  bool player = false;
  init_field();
  unsigned short cell_n, steps_count = 0;

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
          game_error_code(GameError::INCORRECT_INPUT);
          continue;
        }

        if (!make_step(cell_n - 1, (!player ? Cell::X : Cell::O)))
          game_error_code(GameError::CANT_MOVE_HERE);
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
}