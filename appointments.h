#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H
#include "dialog.h"

#include <QDialog>

namespace Ui {
class Appointments;
}

class Appointments : public QDialog
{
    Q_OBJECT

public:
    explicit Appointments(QWidget *parent = 0);
    ~Appointments();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Appointments *ui;
};

#endif // APPOINTMENTS_H
