#include "secondWindow.h"
#include "ui_secondWindow.h"

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::SecondWindow) {
    ui->setupUi(this);
}

SecondWindow::~SecondWindow() {
    delete ui;
}
