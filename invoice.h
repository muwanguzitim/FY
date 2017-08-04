#ifndef INVOICE_H
#define INVOICE_H

#include <QDialog>

namespace Ui {
class Invoice;
}

class Invoice : public QDialog
{
    Q_OBJECT

public:
    explicit Invoice(QWidget *parent = 0);
    ~Invoice();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Invoice *ui;
};

#endif // INVOICE_H
