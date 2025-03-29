#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QPropertyAnimation>
#include "secondWindow.h"

namespace Ui {
    class MainWindow;  // Изменили с Dialog на MainWindow
}

class MainWindow : public QDialog {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;  // Изменили тип указателя
    SecondWindow *secondWindow;
    void animateButtons();
};

#endif // MAINWINDOW_H
