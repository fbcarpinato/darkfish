#include <iostream>
#include <QApplication>

#include "src/gui/GUI.h"
#include "src/gui/BoardPrinter.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Board board;

    std::string startingPositionFen = "3r1r1k/p6p/3N2p1/2P2p2/3bp3/7P/P4PP1/R1B2K2 w - - 0 23";
    board.setupFromFen(startingPositionFen);

    GUI gui(&board);
    gui.show();
    gui.setFixedSize(gui.size());

    BoardPrinter::print(board);

    return QApplication::exec();
}