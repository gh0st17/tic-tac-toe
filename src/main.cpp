#include "../libs/libGame/Game.hpp"

int main() {
  try {
    run();

    return 0;
  }
  catch (std::bad_alloc const&) {
    std::cerr << "Can't allocate memory";
  }
  catch (const std::exception& e) {
    std::cerr << "Exception: "
              << e.what() << std::endl;
  }

  return 1;
}