#include <iostream>
#include <QApplication>

#include "src/gui/GUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GUI gui;

    gui.show();

    return QApplication::exec();
}