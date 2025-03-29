#include "secondWindow.h"
#include "../build/EasyTickets_autogen/include/ui_secondWindow.h"  // Явный путь

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::SecondWindow) {
    ui->setupUi(this);
}

SecondWindow::~SecondWindow() {
    delete ui;
}
