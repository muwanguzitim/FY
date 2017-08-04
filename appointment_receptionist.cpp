 #include "appointment_receptionist.h"
#include "ui_appointment_receptionist.h"
#include "dialog.h"
#include "schedule.h"
#include <QMessageBox>
#include "appointments.h"


Appointment_receptionist::Appointment_receptionist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointment_receptionist)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Appointment_receptionist::~Appointment_receptionist()
{
    delete ui;
}

void Appointment_receptionist::on_pushButton_5_clicked()
{
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateX = dateTime.toString("dd/MM/yyyy");

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from appointment where AppointmentDate='"+dateX+"'");

    if(qry.exec())
     {
        while (qry.next())
         {
            qDebug() << qry.value(0).toString()+"--"+qry.value(1).toString()+"--"+qry.value(2).toString()+"--"+qry.value(4).toString();
            QString angela = "smsappoint&email="+qry.value(5).toString()+"&phone="+qry.value(6).toString()+"&message="+qry.value(2).toString();
            sendRequest(angela);
            QString angela2 = "emailappoint&email="+qry.value(5).toString()+"&phone="+qry.value(6).toString()+"&message="+qry.value(2).toString();
            sendRequest(angela2);
        }
        QMessageBox::information(this,tr("Success"),tr("SMS and Email has been sent"));
        conn.connClose();
     }
    else
     {
        QMessageBox::critical(this,tr("Error"),tr("Check your internet connection"));
     }
}

void Appointment_receptionist::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from appointment");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
}

void Appointment_receptionist::on_pushButton_4_clicked()
{
    this->hide();
    Schedule myS;
    myS.setModal(true);
    myS.exec();
}

