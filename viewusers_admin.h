#ifndef VIEWUSERS_ADMIN_H
#define VIEWUSERS_ADMIN_H

#include <QDialog>

namespace Ui {
class ViewUsers_Admin;
}

class ViewUsers_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit ViewUsers_Admin(QWidget *parent = 0);
    ~ViewUsers_Admin();

private slots:

    void on_pushButton_clicked();

private:
    Ui::ViewUsers_Admin *ui;
};

#endif // VIEWUSERS_ADMIN_H
