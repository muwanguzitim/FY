#ifndef REPORT_H
#define REPORT_H

#include <QDialog>

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    ~Report();

private slots:

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Report *ui;
};

#endif // REPORT_H
