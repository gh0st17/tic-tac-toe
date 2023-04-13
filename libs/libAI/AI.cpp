#include "AI.hpp"
#include "../libGame/Game.hpp"
#include <thread>
#include <chrono>

// Функция для генерации хода компьютером
unsigned short generateMove(Cell* board) {
  unsigned short move = 10; // Индекс клетки, в которую сделает ход компьютер

  // Проверяем, есть ли выигрышные ходы
  for (unsigned short i = 0; i < 9; ++i) {
    if (board[i] == Cell::Unused) {
      board[i] = Cell::X; // Предполагаемый ход компьютера
      // Проверяем, выиграет ли компьютер после этого хода
      // Здесь можно добавить свою логику для определения выигрышной позиции
      if (check_win_state()) {
        move = i;
        board[i] = Cell::Unused;
        break;
      }
      board[i] = Cell::Unused; // Отменяем предполагаемый ход компьютера
    }
  }

    // Если нет выигрышных ходов, блокируем ходы соперника
  if (move == 10) {
    for (int i = 0; i < 9; ++i) {
      if (board[i] == Cell::Unused) {
        board[i] = Cell::O; // Предполагаемый ход соперника
        // Проверяем, выиграет ли соперник после этого хода
        // Здесь можно добавить свою логику для блокировки выигрышных ходов соперника
        if (check_win_state()) {
          move = i;
          board[i] = Cell::Unused;
          break;
        }
        board[i] = Cell::Unused; // Отменяем предполагаемый ход соперника
      }
    }
  }

  // Если нет выигрышных и блокирующих ходов, выбираем случайный ход
  if (move == 10) {
    move = rand() % 9;
  }

  return move;
}

unsigned short computer_step() {
  return generateMove(get_field());
}