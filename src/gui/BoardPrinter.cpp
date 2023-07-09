#include <string>
#include <iostream>
#include "BoardPrinter.h"

void BoardPrinter::print(const Board& board) {
    for (int rank = Board::BOARD_ROWS - 1; rank >= 0; --rank) {
        for (int file = 0; file < Board::BOARD_COLS; ++file) {
            int piece = board.getPieceAtSquare({rank, file});
            if (piece != -1) {
                auto color = static_cast<PieceColor>(piece / 6);
                auto type = static_cast<PieceType>(piece % 6);
                std::string pieceColor = (color == PieceColor::WHITE) ? "W" : "B";
                std::string pieceType;
                switch (type) {
                    case PieceType::KING: pieceType = "K"; break;
                    case PieceType::QUEEN: pieceType = "Q"; break;
                    case PieceType::ROOK: pieceType = "R"; break;
                    case PieceType::BISHOP: pieceType = "B"; break;
                    case PieceType::KNIGHT: pieceType = "N"; break;
                    case PieceType::PAWN: pieceType = "P"; break;
                    case PieceType::None:
                        break;
                }
                std::cout << pieceColor << pieceType << " ";
            } else {
                std::cout << "__ ";
            }
        }
        std::cout << std::endl;
    }
}
