#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT



public:
    explicit Schedule(QWidget *parent = 0);
    ~Schedule();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Schedule *ui;
};

#endif // SCHEDULE_H
