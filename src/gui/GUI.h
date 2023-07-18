#ifndef DARKFISH_GUI_H
#define DARKFISH_GUI_H

#include "QMainWindow"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"
#include "../engine/Board.h"

class GUI : public QMainWindow {
public:
    GUI(Board *board);

private:
    Board* board;

    Square selectedSquare = Square::invalid();

    void renderBoard();

    void handleButtonClick(int row, int col);
};

#endif
