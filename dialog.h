#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("/home/tim/Desktop/hmsdatabase/hms.db");

        if(!mydb.open()){
            qDebug()<<("x");
            return false;
        }
        else{
            qDebug()<<("+");
            return true;
        }
    }

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
