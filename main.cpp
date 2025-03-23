#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "ui_registration_form.h"  // Подключаем сгенерированный файл

class RegistrationDialog : public QDialog, private Ui::Dialog {  // Используем Ui::Dialog
    Q_OBJECT

public:
    explicit RegistrationDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setupUi(this);  // Инициализация интерфейса

        // Подключение сигналов к слотам
        connect(registerButton, &QPushButton::clicked, this, &RegistrationDialog::onRegisterButtonClicked);
        connect(loginButton, &QPushButton::clicked, this, &RegistrationDialog::onLoginButtonClicked);
    }

private slots:
    void onRegisterButtonClicked() {
        QString username = usernameLineEdit->text();
        QString password = passwordLineEdit->text();

        // Проверка введенных данных
        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Поля не могут быть пустыми!");
            return;
        }

        // Логика регистрации (например, сохранение в файл)
        QFile file("users.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << username << ":" << password << "\n";
            file.close();
        }

        QMessageBox::information(this, "Успех", "Пользователь зарегистрирован!");
    }

    void onLoginButtonClicked() {
        // Логика перехода на форму входа
        QMessageBox::information(this, "Вход", "Переход на форму входа...");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    RegistrationDialog dialog;
    dialog.show();

    return app.exec();
}

#include "main.moc"
