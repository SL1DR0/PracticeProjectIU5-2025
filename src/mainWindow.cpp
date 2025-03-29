#include "mainWindow.h"
#include "ui_mainWindow.h"  // Убедитесь, что этот файл существует

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::MainWindow) {  // Изменили на Ui::MainWindow
    ui->setupUi(this);
    secondWindow = new SecondWindow(this);
}
MainWindow::~MainWindow() {
    delete ui;
    delete secondWindow;
}

void MainWindow::animateButtons() {
    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->registerButton, "geometry");
    animation1->setDuration(500);
    animation1->setStartValue(ui->registerButton->geometry());
    animation1->setEndValue(QRect(ui->registerButton->x(), ui->registerButton->y() - 100,
                                  ui->registerButton->width(), ui->registerButton->height()));

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->loginButton, "geometry");
    animation2->setDuration(500);
    animation2->setStartValue(ui->loginButton->geometry());
    animation2->setEndValue(QRect(ui->loginButton->x(), ui->loginButton->y() - 100,
                                  ui->loginButton->width(), ui->loginButton->height()));

    animation1->start();
    animation2->start();

    connect(animation2, &QPropertyAnimation::finished, this, [this]() {
        this->hide();
        secondWindow->show();
    });
}

void MainWindow::on_registerButton_clicked() {
    animateButtons();
}

void MainWindow::on_loginButton_clicked() {
    animateButtons();
}
