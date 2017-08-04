#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QDialog>

namespace Ui {
class Admin_login;
}

class Admin_login : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_login(QWidget *parent = 0);
    ~Admin_login();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Admin_login *ui;
};

#endif // ADMIN_LOGIN_H
