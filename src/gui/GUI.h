#ifndef DARKFISH_GUI_H
#define DARKFISH_GUI_H

#include "QMainWindow"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"

class GUI : public QMainWindow {
public:
    GUI();

private:
    void handleButtonClick();

    void connectButtons();
};

#endif
