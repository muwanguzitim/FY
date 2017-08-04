#include "addprescription_admin.h"
#include "ui_addprescription_admin.h"
#include "dialog.h"

AddPrescription_Admin::AddPrescription_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPrescription_Admin)
{
    ui->setupUi(this);


    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

AddPrescription_Admin::~AddPrescription_Admin()
{
    delete ui;
}

void AddPrescription_Admin::on_pushButton_clicked()
{
    Dialog conn;
    QString date,itemname,qty,amount;
    date=ui->lineEdit->text();
    itemname=ui->lineEdit_2->text();
    qty=ui->lineEdit_3->text();
    amount=ui->lineEdit_4->text();


    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into prescription_admin (Date,Prescription,Qty,Amount) "
                "values('"+date+"','"+itemname+"','"+qty+"','"+amount+"')");

    qry.exec();
}
