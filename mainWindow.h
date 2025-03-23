#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPropertyAnimation>

// Подключите сгенерированный файл
#include "ui_mainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }  // Убедитесь, что это MainWindow
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRegisterButtonClicked();
    void onLoginButtonClicked();

private:
    Ui::MainWindow *ui;  // Указатель на сгенерированный интерфейс
    QPropertyAnimation *animation;
    QDialog *secondWindow;
};

#endif // MAINWINDOW_H
