#ifndef APPOINTMENT_RECEPTIONIST_H
#define APPOINTMENT_RECEPTIONIST_H

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
class Appointment_receptionist;
}

class Appointment_receptionist : public QDialog
{
    Q_OBJECT

public:

    void sendRequest(QString xyz){

        // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"
        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( QUrl( QString("https://victoryuganda.com:5907/angela?req="+xyz) ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        if (reply->error() == QNetworkReply::NoError) {
            //success
            qDebug() << "Success" <<reply->readAll();
            delete reply;
        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }
    }

public:
    explicit Appointment_receptionist(QWidget *parent = 0);
    ~Appointment_receptionist();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Appointment_receptionist *ui;
};

#endif // APPOINTMENT_RECEPTIONIST_H
