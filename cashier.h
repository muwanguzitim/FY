#ifndef CASHIER_H
#define CASHIER_H

#include <QDialog>

namespace Ui {
class Cashier;
}

class Cashier : public QDialog
{
    Q_OBJECT

public:
    explicit Cashier(QWidget *parent = 0);
    ~Cashier();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Cashier *ui;
};

#endif // CASHIER_H
