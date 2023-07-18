#include <QSignalMapper>
#include <QDir>
#include "GUI.h"
#include "BoardPrinter.h"
#include <iostream>
#include <QMessageBox>

GUI::GUI(Board* board) : QMainWindow(), board(board) {
    setWindowTitle("Chess GUI");
    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    auto *gridLayout = new QGridLayout(centralWidget);
    centralWidget->setLayout(gridLayout);
    centralWidget->setFixedSize(600, 600);

    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setVerticalSpacing(0);

    int buttonSize = centralWidget->height() / 8;

    for (int rank = Board::BOARD_ROWS - 1; rank >= 0; --rank) {
        for (int file = 0; file < Board::BOARD_COLS; ++file) {
            auto* button = new QPushButton(this);
            button->setObjectName("ChessButton_" + QString::number(rank) + "_" + QString::number(file));
            button->setFixedSize(buttonSize, buttonSize);
            gridLayout->addWidget(button, rank, file);

            connect(button, &QPushButton::clicked, this, [this, rank, file]() {
                handleButtonClick(rank, file);
            });
        }
    }

    renderBoard();
}

void GUI::renderBoard() {
    QDir parentDir("../assets");
    QString spriteImagePath = parentDir.absoluteFilePath("sprites.png");

    QImage spriteImage(spriteImagePath);

    QMap<PieceType, QRect> spritePositions;

    spritePositions.insert(PieceType::KING, QRect(20, 40, 120, 120));
    spritePositions.insert(PieceType::QUEEN, QRect(160, 40, 120, 120));
    spritePositions.insert(PieceType::BISHOP, QRect(300, 40, 120, 120));
    spritePositions.insert(PieceType::KNIGHT, QRect(440, 40, 120, 120));
    spritePositions.insert(PieceType::ROOK, QRect(580, 40, 120, 120));
    spritePositions.insert(PieceType::PAWN, QRect(720, 40, 120, 120));

    for (int rank = Board::BOARD_ROWS - 1; rank >= 0; --rank) {
        for (int file = 0; file < Board::BOARD_COLS; ++file) {
            QString objectName = "ChessButton_" + QString::number(rank) + "_" + QString::number(file);
            auto* button = findChild<QPushButton*>(objectName);
            if (button) {
                button->setText("");
                int piece = board->getPieceAtSquare({rank, file});
                if (piece != -1) {
                    auto pieceType = static_cast<PieceType>(piece % 6);

                    const QRect& spritePosition = spritePositions.value(pieceType);
                    QImage pieceSprite = spriteImage.copy(spritePosition);

                    button->setIcon(QIcon(QPixmap::fromImage(pieceSprite)));
                    button->setIconSize(button->size() - QSize(10, 10));
                } else {
                    button->setIcon(QIcon());
                }

                if (selectedSquare.rank == rank && selectedSquare.file == file) {
                    button->setStyleSheet("background-color: yellow");
                } else if ((rank + file) % 2 == 0) {
                    button->setStyleSheet("background-color: white");
                } else {
                    button->setStyleSheet("background-color: green");
                }
            }
        }
    }

    BoardPrinter::print(*board);
}

void GUI::handleButtonClick(int row, int col) {
    if (selectedSquare.isValid()) {
        // There is already a selected square
        Move move(selectedSquare, {row, col});
        if (board->isValidMove(move)) {
            // The move is valid, perform it
            board->makeMove(move);

            // Deselect the square
            selectedSquare = Square::invalid();
        } else {
            // The move is invalid, show an error message
            QMessageBox::warning(this, "Invalid Move", "Invalid move selected. Please choose a valid move.");
        }
    } else {
        int piece = board->getPieceAtSquare({row, col});
        if (piece != -1) {
            selectedSquare = {row, col};
        }
    }

    renderBoard();
}
