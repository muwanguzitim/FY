#ifndef PHARMACY_H
#define PHARMACY_H
#include "dialog.h"

#include <QDialog>

namespace Ui {
class Pharmacy;
}

class Pharmacy : public QDialog
{
    Q_OBJECT

public:
    explicit Pharmacy(QWidget *parent = 0);
    ~Pharmacy();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Pharmacy *ui;
};

#endif // PHARMACY_H
