#include "GUI.h"

GUI::GUI() : QMainWindow() {
        setWindowTitle("Chess GUI");
        auto *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        auto *gridLayout = new QGridLayout(centralWidget);
        centralWidget->setLayout(gridLayout);

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                auto *button = new QPushButton(this);
                button->setFixedSize(50, 50);
                gridLayout->addWidget(button, row, col);
            }
        }

        auto *statusLabel = new QLabel(this);
        gridLayout->addWidget(statusLabel, 8, 0, 1, 8);

        connectButtons();

        statusLabel->setText("Chess GUI Initialized");
}

void GUI::connectButtons() {
    QList<QPushButton *> buttons = findChildren<QPushButton *>();
    for (QPushButton *button : buttons) {
        connect(button, &QPushButton::clicked, this, &GUI::handleButtonClick);
    }
}

void GUI::handleButtonClick() {
    auto *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        // Handle the button click event
        // Add your chess logic here
    }
}