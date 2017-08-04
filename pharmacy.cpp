#include "pharmacy.h"
#include "ui_pharmacy.h"
#include <QMessageBox>

Pharmacy::Pharmacy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pharmacy)
{
    ui->setupUi(this);

    Dialog conn;
    if(!conn.connOpen())
        ui->label_14->setText("x");
    else
        ui->label_14->setText("+");

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Pharmacy::~Pharmacy()
{
    delete ui;
}

void Pharmacy::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientid;
    patientid=ui->txt_pid->text();

    qry->prepare("select * from pharmacy where PatientID='"+patientid+"' and Status=:sub");
    qry->bindValue(":sub","Pending");

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    if(qry->exec())
    {
        model->setQuery(*qry);
        ui->tableView->setModel(model);

            int count=0;
            while(qry->next())
            {
                count++;
            }
            if(count==1)
                ui->label_fill->setText(" ");

            if(count<1)
                ui->label_fill->setText(" ");

            if(count>1)
                ui->label_fill->setText("Fill in the *missing fields");
             }
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }


void Pharmacy::on_pushButton_2_clicked()
{
    Dialog conn;
    QString pid;
    pid=ui->txt_pid->text();

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("UPDATE pharmacy SET Status=:sub WHERE PatientID=:pid");
    qry.bindValue(":sub", "Submitted");
    qry.bindValue(":pid", pid);

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Inventory updated"),tr("Drugs have been submitted"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    conn.connClose();

}


void Pharmacy::on_pushButton_5_clicked()
{
    Dialog conn;
    QString pid,it,qty,presid;
    pid=ui->txt_pid->text();
    it=ui->txt_it->text();
    qty=ui->txt_qty->text();
    presid=ui->txt_id->text();


    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
     }
    conn.connOpen();
    QSqlQuery qry;

    qry.prepare("UPDATE pharmacy SET ItemName=:it,Qty=:qty WHERE PrescriptionID=:id");
    qry.bindValue(":it", it);
    qry.bindValue(":qty", qty);
    qry.bindValue(":id", presid);

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Updated"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
    conn.connClose();

    }
