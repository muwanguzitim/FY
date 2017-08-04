#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "admin.h"
#include "admin_login.h"
#include <QCryptographicHash>
#include "navigation_cashier.h"
#include "navigation_doctor.h"
#include "navigation_laboratory.h"
#include "navigation_nurse.h"
#include "navigation_pharmacy.h"
#include "navigation_receptionist.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    if(!connOpen())
        ui->label_4->setText("x");
    else
        ui->label_4->setText("+");

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{

    QString username,password,userx;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();
    userx=ui->lineEdit_username->text();

    QString hms = userx.mid(0, 3);
    qDebug() << hms;

    QString queryStr;
    queryStr = QString("%1").arg(QString(QCryptographicHash::hash(ui->lineEdit_password->text().toUtf8(),QCryptographicHash::Md5).toHex()));


    QSqlQuery qry;
    qry.prepare("select * from login where username='"+username+"' and password='"+queryStr+"'");


   if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }

        if(count==1)
         {
            this->hide();
            if(hms=="Adm"){
                Admin myNav;
                myNav.setModal(true);
                myNav.exec();
            }else if(hms=="Nur"){
                Navigation_nurse myNav;
                myNav.setModal(true);
                myNav.exec();
            }else if(hms=="Pha"){
                Navigation_Pharmacy myNav;
                myNav.setModal(true);
                myNav.exec();
            }else if(hms=="Cas"){
                Navigation_Cashier myNav;
                myNav.setModal(true);
                myNav.exec();
            }else if(hms=="Lab"){
                Navigation_Laboratory myNav;
                myNav.setModal(true);
                myNav.exec();
            }else if(hms=="Rec"){
                Navigation_receptionist myNav;
                myNav.setModal(true);
                myNav.exec();
            }else if(hms=="Doc"){
                Navigation_doctor myNav;
                myNav.setModal(true);
                myNav.exec();
            }

            connClose();
         }
           if(count>1)
            ui->label_5->setText("Duplicate username and password");

        if(count<1)
            ui->label_5->setText("username and password is not correct");
    }
}


void Dialog::on_pushButton_2_clicked()
{
    this->hide();
    Admin_login myNav;
    myNav.setModal(true);
    myNav.exec();

}
