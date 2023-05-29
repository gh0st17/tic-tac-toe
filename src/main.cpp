#include "../libs/libAI/AI.hpp"
#include "../libs/libUI/UI.hpp"
#include "../libs/libError/Error.hpp"
#include "../libs/libGame/Game.hpp"

void run(bool mode);

int main(int argc, const char* argv[]) {
  if (argc > 1) {
    if (std::string(argv[1]) == "AI") {
      init_AI();
      run(false);
    }
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
  bool player = (!mode ? true : false);
  init_field();
  unsigned short cell_n, steps_count = 0;

  auto print = []() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    print_field();
  };

  print();
  while (!check_win_state() && steps_count++ < 9U) {
    if (!mode && !player) {
      cell_n = computer_step();
      if (cell_n == 9) {
        game_error_code(GameError::FIELD_FULL);
        destroy_field();
        exit(1);
      }
      if (cell_n == 10 || !make_step(cell_n, Cell::X)) {
        game_error_code(GameError::AI_UNKNOWN_STEP);
        destroy_field();
        exit(1);
      }
    }
    else
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