#ifndef MEDICINE_ADMIN_H
#define MEDICINE_ADMIN_H

#include <QDialog>

namespace Ui {
class Medicine_Admin;
}

class Medicine_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Medicine_Admin(QWidget *parent = 0);
    ~Medicine_Admin();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Medicine_Admin *ui;
};

#endif // MEDICINE_ADMIN_H
