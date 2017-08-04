#ifndef READYRESULTS_H
#define READYRESULTS_H

#include <QDialog>

namespace Ui {
class ReadyResults;
}

class ReadyResults : public QDialog
{
    Q_OBJECT

public:
    explicit ReadyResults(QWidget *parent = 0);
    ~ReadyResults();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ReadyResults *ui;
};

#endif // READYRESULTS_H
