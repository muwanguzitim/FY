#ifndef PHARMACY_NEWSTOCK_H
#define PHARMACY_NEWSTOCK_H

#include <QDialog>

namespace Ui {
class Pharmacy_newstock;
}

class Pharmacy_newstock : public QDialog
{
    Q_OBJECT

public:
    explicit Pharmacy_newstock(QWidget *parent = 0);
    ~Pharmacy_newstock();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Pharmacy_newstock *ui;
};

#endif // PHARMACY_NEWSTOCK_H
