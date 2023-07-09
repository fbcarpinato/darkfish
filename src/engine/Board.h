#ifndef DARKFISH_BOARD_H
#define DARKFISH_BOARD_H

#include <memory>

#include "Piece.h"

struct Square {
    int rank;
    int file;
};

struct Move {
    Square sourceSquare;
    Square targetSquare;
};


class Board {

public:
    static constexpr int BOARD_SIZE = 64;
    static constexpr int BOARD_ROWS = 8;
    static constexpr int BOARD_COLS = 8;

    uint64_t bitboards[12];

    uint64_t occupancy[2];

    void setupFromFen(const std::string& fen);

    void setPieceOnSquare(PieceType type, PieceColor color, const Square& square);

    [[nodiscard]] int getPieceAtSquare(const Square& square) const;

    [[nodiscard]] int getSquareIndex(Square square) const;

    void clearSquare(Square square);

    [[nodiscard]] PieceType getPieceType(Square square) const;

    [[nodiscard]] PieceColor getPieceColor(Square square) const;

    void makeMove(const Move &move);
};


#endif
