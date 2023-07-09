cmake_minimum_required(VERSION 3.25)
project(darkfish)

set(CMAKE_CXX_STANDARD 23)

add_executable(darkfish main.cpp src/Board.cpp src/Board.h src/Piece.h engine/ai/evaluate.h engine/ai/pieceTableBoards.h src/BoardPrinter.cpp src/BoardPrinter.h)
