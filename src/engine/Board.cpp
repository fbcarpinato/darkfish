#include <iostream>
#include "Board.h"

void Board::setupFromFen(const std::string& fen) {
    for (unsigned long long & bitboard : bitboards) {
        bitboard = 0;
    }
    for (unsigned long long & i : occupancy) {
        i = 0;
    }

    int rank = 7;
    int file = 0;
    size_t i = 0;

    while (fen[i] != ' ') {
        if (isdigit(fen[i])) {
            int emptySquares = fen[i] - '0';
            file += emptySquares;
        } else if (fen[i] == '/') {
            rank--;
            file = 0;
        } else {
            PieceColor color = isupper(fen[i]) ? PieceColor::WHITE : PieceColor::BLACK;
            PieceType type;
            char piece = toupper(fen[i]);
            switch (piece) {
                case 'P': type = PieceType::PAWN; break;
                case 'N': type = PieceType::KNIGHT; break;
                case 'B': type = PieceType::BISHOP; break;
                case 'R': type = PieceType::ROOK; break;
                case 'Q': type = PieceType::QUEEN; break;
                case 'K': type = PieceType::KING; break;
                default: type = PieceType::None; break;
            }
            setPieceOnSquare(type, color, {rank, file});
            file++;
        }
        i++;
    }

    // The remaining parts of the FEN string contain the active color,
    // castling availability, en passant target square, halfmove clock and fullmove number.
    // These would be handled here...
}

int Board::getPieceAtSquare(const Square& square) const {
    int squareIndex = square.rank * BOARD_COLS + square.file;
    for (int piece = 0; piece < 12; ++piece) {
        if (bitboards[piece] & (1ULL << squareIndex)) {
            return piece;
        }
    }
    return -1;
}

void Board::setPieceOnSquare(PieceType type, PieceColor color, const Square& square) {
    auto squareIndex = getSquareIndex(square);

    // Clear the starting square on the bitboard for the specified piece type and color.
    int pieceIndex = static_cast<int>(type) + 6 * static_cast<int>(color);
    bitboards[pieceIndex] &= ~(1ULL << squareIndex);

    // Set the piece on the target square.
    bitboards[pieceIndex] |= (1ULL << squareIndex);

    // Set the target square on the appropriate color's occupancy bitboard.
    occupancy[static_cast<int>(color)] |= (1ULL << squareIndex);
}

int Board::getSquareIndex(Square square) const {
    return  square.rank * BOARD_COLS + square.file;;
}

void Board::clearSquare(Square square) {
    auto squareIndex = getSquareIndex(square);
    unsigned long long mask = ~(1ULL << squareIndex);

    // Identify which piece is on the square.
    for (int piece = 0; piece < 12; ++piece) {
        if (bitboards[piece] & (1ULL << squareIndex)) {
            bitboards[piece] &= mask; // Clear the bitboard for this piece.
            break;
        }
    }

    // Identify which color's piece is on the square.
    if (occupancy[static_cast<int>(PieceColor::WHITE)] & (1ULL << squareIndex)) {
        occupancy[static_cast<int>(PieceColor::WHITE)] &= mask; // Clear the white occupancy bitboard.
    } else if (occupancy[static_cast<int>(PieceColor::BLACK)] & (1ULL << squareIndex)) {
        occupancy[static_cast<int>(PieceColor::BLACK)] &= mask; // Clear the black occupancy bitboard.
    }
}

PieceType Board::getPieceType(Square square) const {
    auto squareIndex = getSquareIndex(square);
    for (int piece = 0; piece < 12; ++piece) {
        if (bitboards[piece] & (1ULL << squareIndex)) {
            return static_cast<PieceType>(piece % 6);
        }
    }
    return PieceType::None;
}

PieceColor Board::getPieceColor(Square square) const {
    auto squareIndex = getSquareIndex(square);
    for (int piece = 0; piece < 12; ++piece) {
        if (bitboards[piece] & (1ULL << squareIndex)) {
            return static_cast<PieceColor>(piece / 6);
        }
    }
    return PieceColor::None;
}

void Board::makeMove(const Move& move) {
    PieceType pieceType = getPieceType(move.sourceSquare);
    PieceColor pieceColor = getPieceColor(move.sourceSquare);

    clearSquare(move.sourceSquare);

    setPieceOnSquare(pieceType, pieceColor, move.targetSquare);
}

bool Board::isValidMove(const Move& move) const {
    if (!move.targetSquare.isValid()) {
        return false;
    }

    if (move.sourceSquare == move.targetSquare) {
        return false;
    }

    PieceType pieceType = getPieceType(move.sourceSquare);
    PieceColor pieceColor = getPieceColor(move.sourceSquare);

    // Implement the logic to validate the move based on the rules of the game
    // You can consider factors like piece type, source and target squares, current board state, and any game-specific rules

    // For example, you can check if the target square is empty or occupied by an opponent's piece
    // You can also implement specific rules for each piece type

    return true; // Placeholder return statement
}