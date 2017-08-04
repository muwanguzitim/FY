#ifndef ADDPRESCRIPTION_ADMIN_H
#define ADDPRESCRIPTION_ADMIN_H

#include <QDialog>

namespace Ui {
class AddPrescription_Admin;
}

class AddPrescription_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit AddPrescription_Admin(QWidget *parent = 0);
    ~AddPrescription_Admin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddPrescription_Admin *ui;
};

#endif // ADDPRESCRIPTION_ADMIN_H
