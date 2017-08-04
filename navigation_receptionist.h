#ifndef NAVIGATION_RECEPTIONIST_H
#define NAVIGATION_RECEPTIONIST_H

#include <QDialog>

namespace Ui {
class Navigation_receptionist;
}

class Navigation_receptionist : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation_receptionist(QWidget *parent = 0);
    ~Navigation_receptionist();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Navigation_receptionist *ui;
};

#endif // NAVIGATION_RECEPTIONIST_H
