#ifndef LABORATORY_H
#define LABORATORY_H
#include "dialog.h"
#include <QDialog>

namespace Ui {
class Laboratory;
}

class Laboratory : public QDialog
{
    Q_OBJECT

public:
    explicit Laboratory(QWidget *parent = 0);
    ~Laboratory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Laboratory *ui;
};

#endif // LABORATORY_H
