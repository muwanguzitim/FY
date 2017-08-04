#include "receiptionist.h"
#include "ui_receiptionist.h"
#include <QMessageBox>
#include <QtSql>
#include "searchpatient.h"
#include <QTime>


Receiptionist::Receiptionist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Receiptionist)
{
    ui->setupUi(this);

    Dialog conn;
    if(!conn.connOpen())
        ui->label_26->setText("x");
    else
        ui->label_26->setText("+");


    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Receiptionist::~Receiptionist()
{
    delete ui;
}

void Receiptionist::on_pushButton_clicked()
{
    Dialog conn;
    QString patientname,dob,pno,occupation,sname,residence,religion,gname,grelation,goccupation,gpno,gemail,male,female;
    patientname=ui->txt_FName->text();
    dob=ui->txt_DOB->text();
    pno=ui->txt_Pno->text();
    occupation=ui->txt_occupation->text();
    sname=ui->txt_Sname->text();
    residence=ui->txt_residence->text();
    religion=ui->txt_religion->text();
    gname=ui->txt_GName->text();
    grelation=ui->txt_GRelation->text();
    goccupation=ui->txt_Goccupation->text();
    gpno=ui->txt_GPno->text();
    gemail=ui->txt_email->text();
    male=ui->radioButton->isChecked();
    female=ui->radioButton_2->isChecked();


    if(patientname.toInt()||occupation.toInt()||sname.toInt()||religion.toInt()||gname.toInt()||goccupation.toInt()||grelation.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Patient name, occupation, surname, religion, guardian name, guardian relation and guardian occupation cannot contain numeric values"));
    }else if(!gpno.toInt()||!pno.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Phone numbers should be numbers only"));
    }else{

        if(!conn.connOpen()){
            qDebug()<<"Failed to open the database";
            return;
        }


        conn.connOpen();
        QSqlQuery qry;
        int ck = QDateTime::currentMSecsSinceEpoch();
        QString sk = QString::number(ck);
        QDateTime dateTime = dateTime.currentDateTime();
        QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

        if(ui->radioButton->isChecked())
        {
            qry.prepare("insert into patient (Gender) values('"+male+"')");
            qry.exec();
        }
        if (ui->radioButton_2->isChecked())
        {
            qry.prepare("insert into patient (Gender) values('"+female+"')");
            qry.exec();
        }

        qry.prepare("insert into patient (PatientID,PatientName,DOB,phone,occupation,Residence,Religion,GuardianName,Relation,Goccupation,GuardianPhone,JoinDate,Email) "
                    "values('"+sk+"','"+patientname+"','"+dob+"','"+pno+"','"+occupation+"','"+residence+"','"+religion+"','"+gname+"','"+grelation+"','"+goccupation+"','"+gpno+"','"+dateTimeString+"','"+gemail+"')");
        if(qry.exec())
        {
            QMessageBox::information(this,tr("Success"),tr("Added"));
            conn.connClose();
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    }

}

void Receiptionist::on_pushButton_3_clicked()
{
    this->hide();
    SearchPatient myRec;
    myRec.setModal(true);
    myRec.exec();
}
