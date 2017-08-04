#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <QDialog>

namespace Ui {
class WaitingList;
}

class WaitingList : public QDialog
{
    Q_OBJECT

public:
    explicit WaitingList(QWidget *parent = 0);
    ~WaitingList();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WaitingList *ui;
};

#endif // WAITINGLIST_H
