#include "schedule.h"
#include "ui_schedule.h"
#include "dialog.h"
#include "appointments.h"
#include <QMessageBox>
#include <QTime>
#include "appointment_receptionist.h"

Schedule::Schedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::on_pushButton_2_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientname,lastname,phone;
    patientname=ui->txt_pn->text();
    lastname=ui->txt_ln->text();
    phone=ui->txt_phone->text();

    qry->prepare("select * from patient where PatientName='"+patientname+"' and Surname='"+lastname+"' and phone='"+phone+"'");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->label_9->setText("   ");


    if(qry->exec())
        {
            int count=0;
            while(qry->next())
            {
                count++;
            }

            if(count==1)
             {
                ui->label_9->setText("  ");
            }
                if(count>1)
                ui->label_9->setText("  ");

            if(count<1)
                ui->label_9->setText("Fill in *missing fields");
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }

}

void Schedule::on_pushButton_clicked()
{
    this->hide();
    Appointment_receptionist myA;
    myA.setModal(true);
    myA.exec();
}

void Schedule::on_pushButton_7_clicked()
{
    Dialog conn;
    QString p,dt,de,e,ph;
    p=ui->txt_pid->text();
    dt=ui->txt_dt->text();
    de=ui->txt_details->toPlainText();
    e=ui->txt_email->text();
    ph=ui->txt_phone_2->text();


     QRegExp tagExp(",");
     QStringList firstList = dt.split(tagExp);
     QString dtt = firstList.takeLast();
     QString dtd = firstList.takeFirst();


     if(!ph.toInt()||!p.toInt()){
          QMessageBox::critical(this,tr("Input validation"),tr("PatientID  and Phone Number should be numbers only"));
     }else{

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into appointment (PatientID,AppointmentDate,AppointmentTime,Details,Email,Phone) "
                "values('"+p+"','"+dtd+"','"+dtt+"','"+de+"','"+e+"','"+ph+"')");

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

void Schedule::on_tableView_activated(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(index).toString();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from patient where PatientID='"+id+"' or Email='"+id+"' or phone='"+id+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
            ui->txt_pid->setText(qry.value(0).toString());
            ui->txt_email->setText(qry.value(4).toString());
            ui->txt_phone_2->setText(qry.value(5).toString());

        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}



void Schedule::on_pushButton_3_clicked()
{
    Dialog conn;
    QString p,dt,de,e,ph;
    p=ui->txt_pid->text();
    dt=ui->txt_dt->text();
    de=ui->txt_details->toPlainText();
    e=ui->txt_email->text();
    ph=ui->txt_phone_2->text();

    QRegExp tagExp(",");
    QStringList firstList = dt.split(tagExp);
    QString dtt = firstList.takeLast();
    QString dtd = firstList.takeFirst();

    if(!ph.toInt()||!p.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("PatientID and Phone Number should be numbers only"));
    }else{

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("UPDATE appointment SET AppointmentDate=:ad,AppointmentTime=:at,Details=:d,Email=:e,Phone=:p WHERE PatientID=:pid");
    qry.bindValue(":ad", dtd);
    qry.bindValue(":at", dtt);
    qry.bindValue(":d", de);
    qry.bindValue(":e", e);
    qry.bindValue(":p", ph);
    qry.bindValue(":pid", p);

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Updated"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}
}

void Schedule::on_pushButton_4_clicked()
{
    Dialog conn;
    QString p,dt,de,e,ph;
    p=ui->txt_pid->text();
    dt=ui->txt_dt->text();
    de=ui->txt_details->toPlainText();
    e=ui->txt_email->text();
    ph=ui->txt_phone_2->text();


    if(!ph.toInt()||!p.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("PatientID and Phone Number should be numbers only"));
    }else{

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from appointment where PatientID='"+p+"' ");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Deleted"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    }
}
