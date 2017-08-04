#ifndef GS_ADMIN_H
#define GS_ADMIN_H

#include <QDialog>

namespace Ui {
class GS_Admin;
}

class GS_Admin : public QDialog
{
    Q_OBJECT

public:
    explicit GS_Admin(QWidget *parent = 0);
    ~GS_Admin();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::GS_Admin *ui;
};

#endif // GS_ADMIN_H
