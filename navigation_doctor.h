#ifndef NAVIGATION_DOCTOR_H
#define NAVIGATION_DOCTOR_H

#include <QDialog>

namespace Ui {
class Navigation_doctor;
}

class Navigation_doctor : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation_doctor(QWidget *parent = 0);
    ~Navigation_doctor();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

private:
    Ui::Navigation_doctor *ui;
};

#endif // NAVIGATION_DOCTOR_H
