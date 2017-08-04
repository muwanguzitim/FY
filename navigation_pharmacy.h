#ifndef NAVIGATION_PHARMACY_H
#define NAVIGATION_PHARMACY_H

#include <QDialog>

namespace Ui {
class Navigation_Pharmacy;
}

class Navigation_Pharmacy : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation_Pharmacy(QWidget *parent = 0);
    ~Navigation_Pharmacy();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Navigation_Pharmacy *ui;
};

#endif // NAVIGATION_PHARMACY_H
