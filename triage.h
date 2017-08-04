#ifndef TRIAGE_H
#define TRIAGE_H
#include "dialog.h"

#include <QDialog>

namespace Ui {
class Triage;
}

class Triage : public QDialog
{
    Q_OBJECT

public:
    explicit Triage(QWidget *parent = 0);
    ~Triage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Triage *ui;
};

#endif // TRIAGE_H
