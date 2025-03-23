#include "mainWindow.h"
#include "ui_mainWindow.h"  // Подключите сгенерированный файл
#include "secondWindow.h"
#include <QPropertyAnimation>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {  // Инициализация указателя ui
    ui->setupUi(this);  // Настройка интерфейса

    // Подключение сигналов к слотам
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onRegisterButtonClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);

    // Инициализация анимации
    animation = new QPropertyAnimation(ui->pushButton_2, "geometry");
    animation->setDuration(1000); // Длительность анимации 1 секунда

    // Инициализация второго окна
    secondWindow = new SecondWindow(this);
}

MainWindow::~MainWindow() {
    delete ui;  // Освобождение памяти
}

void MainWindow::onRegisterButtonClicked() {
    // Анимация исчезания кнопки регистрации
    animation->setStartValue(ui->pushButton_2->geometry());
    animation->setEndValue(QRect(ui->pushButton_2->x(), ui->pushButton_2->y() + 200, ui->pushButton_2->width(), ui->pushButton_2->height()));
    animation->start();

    // Переход к новому окну
    secondWindow->show();
    this->hide();
}

void MainWindow::onLoginButtonClicked() {
    // Логика для кнопки входа
    QMessageBox::information(this, "Вход", "Переход на форму входа...");
}
