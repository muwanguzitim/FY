#ifndef NAVIGATION_NURSE_H
#define NAVIGATION_NURSE_H

#include <QDialog>

namespace Ui {
class Navigation_nurse;
}

class Navigation_nurse : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation_nurse(QWidget *parent = 0);
    ~Navigation_nurse();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

private:
    Ui::Navigation_nurse *ui;
};

#endif // NAVIGATION_NURSE_H
