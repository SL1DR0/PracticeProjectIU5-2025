/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *registerButton;
    QPushButton *loginButton;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1392, 805);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(/home/ur0ch/PracticeProjectIU5-2025/images/back.png);  /* \320\237\321\203\321\202\321\214 \320\272 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216 */\n"
"background-position: center;  /* \320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 */\n"
"background-repeat: no-repeat;  /* \320\235\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 */\n"
"background-size: cover;  /* \320\240\320\260\321\201\321\202\321\217\320\275\321\203\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\275\320\260 \320\262\320\265\321\201\321\214 \320\262\320\270\320\264\320\266\320\265\321\202 */"));
        registerButton = new QPushButton(MainWindow);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(320, 420, 231, 51));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-image: url(/home/ur0ch/PracticeProjectIU5-2025/images/registration.png);  /* \320\237\321\203\321\202\321\214 \320\272 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    background-position: center;  /* \320\237\320\276\320\267\320\270\321\206\320\270\321\217 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    border-radius: 25px;  /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    background-repeat: no-repeat;  /* \320\235\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 */\n"
"    background-size: cover;  /* \320\240\320\260\321\201\321\202\321\217\320\275\321\203\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 \320\275\320\260 \320\262\320\265\321"
                        "\201\321\214 \321\204\320\276\320\275 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\203\321\216 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 */\n"
"}"));
        loginButton = new QPushButton(MainWindow);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(860, 410, 221, 51));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-image: url(/home/ur0ch/PracticeProjectIU5-2025/images/in.png);  /* \320\237\321\203\321\202\321\214 \320\272 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    border-radius: 25px;  /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"    background-position: center;  /* \320\237\320\276\320\267\320\270\321\206\320\270\321\217 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    background-repeat: no-repeat;  /* \320\235\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 */\n"
"    background-size: cover;  /* \320\240\320\260\321\201\321\202\321\217\320\275\321\203\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 \320\275\320\260 \320\262\320\265\321\201\321\214"
                        " \321\204\320\276\320\275 */\n"
"	border: none;\n"
"}"));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        registerButton->setText(QString());
        loginButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
