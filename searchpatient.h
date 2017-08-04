#ifndef SEARCHPATIENT_H
#define SEARCHPATIENT_H

#include <QDialog>

namespace Ui {
class SearchPatient;
}

class SearchPatient : public QDialog
{
    Q_OBJECT

public:
    explicit SearchPatient(QWidget *parent = 0);
    ~SearchPatient();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_speciality_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::SearchPatient *ui;
};

#endif // SEARCHPATIENT_H
