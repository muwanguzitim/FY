#ifndef PRESCRIPTION_ADMIN_H
#define PRESCRIPTION_ADMIN_H

#include <QDialog>

namespace Ui {
class Prescription_Admin;
}

class Prescription_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Prescription_Admin(QWidget *parent = 0);
    ~Prescription_Admin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Prescription_Admin *ui;
};

#endif // PRESCRIPTION_ADMIN_H
