#ifndef NAVIGATION_LABORATORY_H
#define NAVIGATION_LABORATORY_H

#include <QDialog>

namespace Ui {
class Navigation_Laboratory;
}

class Navigation_Laboratory : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation_Laboratory(QWidget *parent = 0);
    ~Navigation_Laboratory();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

private:
    Ui::Navigation_Laboratory *ui;
};

#endif // NAVIGATION_LABORATORY_H
