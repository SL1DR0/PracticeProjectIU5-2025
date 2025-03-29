#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
    class SecondWindow;  // Должно совпадать с именем в UI-файле
}

class SecondWindow : public QDialog {
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
