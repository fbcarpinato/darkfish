#ifndef DARKFISH_BOARD_H
#define DARKFISH_BOARD_H

#include <memory>

#include "Piece.h"

struct Square {
    int rank;
    int file;

    bool isValid() const {
        return rank >= 0 && rank < 8 && file >= 0 && file < 8;
    }

    static Square invalid() {
        return {-1, -1};
    }

    bool operator==(const Square& other) const {
        return (rank == other.rank) && (file == other.file);
    }

    bool operator!=(const Square& other) const {
        return !(*this == other);
    }
};

struct Move {
    Square sourceSquare;
    Square targetSquare;

    Move(const Square& source, const Square& target)
        : sourceSquare(source), targetSquare(target) {}
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

    bool isValidMove(const Move& move) const;
};


#endif
