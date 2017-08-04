#ifndef NAVIGATION_CASHIER_H
#define NAVIGATION_CASHIER_H

#include <QDialog>

namespace Ui {
class Navigation_Cashier;
}

class Navigation_Cashier : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation_Cashier(QWidget *parent = 0);
    ~Navigation_Cashier();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Navigation_Cashier *ui;
};

#endif // NAVIGATION_CASHIER_H
