#include "doctor.h"
#include "ui_doctor.h"
#include <QTableView>
#include <QListView>
#include <QTreeView>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRelationalTableModel>
#include "dialog.h"
#include <QTime>
#include <QMessageBox>
#include "waitinglist.h"
#include "readyresults.h"

Doctor::Doctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctor)
{
    ui->setupUi(this);


    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    }


Doctor::~Doctor()
{
    delete ui;
}

void Doctor::on_pushButton_7_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientid;
    patientid=ui->txt_id->text();

    qry->prepare("select * from patient where PatientID='"+patientid+"'");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView_patient->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
    }

}


void Doctor::on_pushButton_clicked()
{
    Dialog conn;
    QString patientid,medicine,qty;
    patientid=ui->txt_id->text();
    medicine=ui->txt_mn->text();
    qty=ui->txt_qty->text();

    int ck = QDateTime::currentMSecsSinceEpoch();
    QString sk = "PE"+QString::number(ck);
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

    if(medicine.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Enter appropriate values"));
    }else
    {

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into pharmacy (PatientID,PrescriptionID,ItemName,Qty,Date) values ('"+patientid+"','"+sk+"','"+medicine+"','"+qty+"','"+dateTimeString+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Sent to pharmacy"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry1 = new QSqlQuery(conn.mydb);

    qry1->prepare("select * from pharmacy where PatientID='"+patientid+"'");

    qry1->exec();
    model->setQuery(*qry1);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());

}
}
void Doctor::on_pushButton_2_clicked()
{
    Dialog conn;
    QString test1,patientid;
    test1=ui->txt_test1->text();
    patientid=ui->txt_id->text();

    int ck = QDateTime::currentMSecsSinceEpoch();
    QString sk = "TE"+QString::number(ck);
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");


    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into laboratory (TestName,TestID,Date,PatientID) values ('"+test1+"','"+sk+"','"+dateTimeString+"','"+patientid+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Sent to laboratory"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}


void Doctor::on_pushButton_3_clicked()
{

    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientid;
    patientid=ui->txt_id->text();

    qry->prepare("select * from triage where PatientID='"+patientid+"'");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView_triage->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
    }
}

void Doctor::on_pushButton_10_clicked()
{
    ReadyResults mySP;
    mySP.setModal(true);
    mySP.exec();
}

void Doctor::on_pushButton_8_clicked()
{
    this->hide();
    WaitingList mySP;
    mySP.setModal(true);
    mySP.exec();
}
