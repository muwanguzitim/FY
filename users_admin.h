#ifndef USERS_ADMIN_H
#define USERS_ADMIN_H

#include <QDialog>

namespace Ui {
class Users_Admin;
}

class Users_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Users_Admin(QWidget *parent = 0);
    ~Users_Admin();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Users_Admin *ui;
};

#endif // USERS_ADMIN_H
