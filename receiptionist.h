#ifndef RECEIPTIONIST_H
#define RECEIPTIONIST_H

#include <QString>
#include <QDebug>
#include "dialog.h"

#include <QDialog>

namespace Ui {
class Receiptionist;
}

class Receiptionist : public QDialog
{
    Q_OBJECT

public:

    explicit Receiptionist(QWidget *parent = 0);
    ~Receiptionist();

private:
    Ui::Receiptionist *ui;

public:
    Receiptionist(const char* driver);



private slots:

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // RECEIPTIONIST_H
