/********************************************************************************
** Form generated from reading UI file 'secondWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(1371, 716);
        SecondWindow->setStyleSheet(QString::fromUtf8("background-image: url(/home/ur0ch/PracticeProjectIU5-2025/images/secondWindowBack.png);  /* \320\237\321\203\321\202\321\214 \320\272 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216 */\n"
"background-position: center;  /* \320\237\320\276\320\267\320\270\321\206\320\270\321\217 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 */\n"
"background-repeat: no-repeat;  /* \320\235\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 */\n"
"background-size: cover;  /* \320\240\320\260\321\201\321\202\321\217\320\275\321\203\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\275\320\260 \320\262\320\265\321\201\321\214 \320\262\320\270\320\264\320\266\320\265\321\202 */"));
        lineEdit = new QLineEdit(SecondWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(580, 220, 211, 81));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-image: url(/home/ur0ch/PracticeProjectIU5-2025/images/white.png);  /* \320\237\321\203\321\202\321\214 \320\272 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    background-position: center;  /* \320\237\320\276\320\267\320\270\321\206\320\270\321\217 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    background-repeat: no-repeat;  /* \320\235\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 */\n"
"    background-size: cover;  /* \320\240\320\260\321\201\321\202\321\217\320\275\321\203\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 \320\275\320\260 \320\262\320\265\321\201\321\214 \321\204\320\276\320\275 */\n"
"    color: Blue;  /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    padding: 5px; "
                        " /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\277\320\276\320\273\321\217 */\n"
"    border: 1px solid gray;  /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 \320\277\320\276\320\273\321\217 */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: Black;  /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\273\320\265\320\271\321\201\321\205\320\276\320\273\320\264\320\265\321\200\320\260 */\n"
"}"));
        lineEdit_2 = new QLineEdit(SecondWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(580, 440, 211, 81));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-image: url(/home/ur0ch/PracticeProjectIU5-2025/images/white.png);  /* \320\237\321\203\321\202\321\214 \320\272 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    background-position: center;  /* \320\237\320\276\320\267\320\270\321\206\320\270\321\217 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\320\270 */\n"
"    background-repeat: no-repeat;  /* \320\235\320\265 \320\277\320\276\320\262\321\202\320\276\321\200\321\217\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 */\n"
"    background-size: cover;  /* \320\240\320\260\321\201\321\202\321\217\320\275\321\203\321\202\321\214 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\216 \320\275\320\260 \320\262\320\265\321\201\321\214 \321\204\320\276\320\275 */\n"
"    color: Blue;  /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    padding: 5px; "
                        " /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \320\277\320\276\320\273\321\217 */\n"
"    border: 1px solid gray;  /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 \320\277\320\276\320\273\321\217 */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: Black;  /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\273\320\265\320\271\321\201\321\205\320\276\320\273\320\264\320\265\321\200\320\260 */\n"
"}"));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "SecondWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
