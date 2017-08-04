#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include "admin.h"
#include "doctor.h"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#include <QObject>
#include <QIODevice>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include "laboratory.h"
#include <iostream>
#include "report.h"
#include <QDebug>
#include "receiptionist.h"


void gen();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;
    w.show();
    gen();

    return a.exec();
}

void gen()
{


}
