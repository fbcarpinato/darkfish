#include <iostream>

#include "src/Board.h"
#include "src/BoardPrinter.h"

int main() {
    Board board;
    board.setupFromFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    // Print the initial board state
    std::cout << "Initial Board State:" << std::endl;
    BoardPrinter::print(board);
    std::cout << std::endl;

    // Make a move (e2 to e4)
    Move move = {{1, 4}, {3, 4}};
    board.makeMove(move);

    // Print the updated board state
    std::cout << "Board State after e2 to e4 move:" << std::endl;
    BoardPrinter::print(board);

    return 0;
}