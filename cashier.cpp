#include "cashier.h"
#include "ui_cashier.h"
#include "dialog.h"

Cashier::Cashier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cashier)
{
    ui->setupUi(this);
    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Cashier::~Cashier()
{
    delete ui;
}


void Cashier::on_pushButton_2_clicked()
{
    Dialog conn;
    QString pid;
    pid=ui->txt_pid->text();

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    int ck = QDateTime::currentMSecsSinceEpoch();
    QString sk = "R"+QString::number(ck);

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into cashier (PatientID,ReceiptNo,PayDate,VisitDate) "
                "values('"+pid+"','"+sk+"','"+dateTimeString+"','"+dateTimeString+"')");
    qry.exec();


    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.mydb);

    qry1->prepare("select * from pharmacy where PatientID='"+pid+"' and Status=:sub");
    qry.bindValue(":sub","0");
    qry1->exec();
    model->setQuery(*qry1);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());


    if(conn.connOpen())
 {
        QSqlQuery querylite;
         QString sqlStr;
         QString mycode;

         sqlStr = "select * from patient where PatientID='"+pid+"'";

         if (querylite.exec(sqlStr)==true) //Executes the query
         {
             while (querylite.next()) //While u have records
             {
                 mycode = querylite.value(querylite.record().indexOf("PatientName")).toString();  //Get the data from the query
                  ui->label_18->setText(mycode);  //set the data to the label

                  mycode = querylite.value(querylite.record().indexOf("SurName")).toString();  //Get the data from the query
                   ui->label_2->setText(mycode);  //set the data to the label

                 mycode = querylite.value(querylite.record().indexOf("PatientID")).toString();
                 ui->label_21->setText(mycode);
             }
         }

         if(conn.connOpen())
         {
             QSqlQuery querylite;
              QString sqlStr1;
              QString mycode1;

                 sqlStr1 = "select * from cashier where PatientID='"+pid+"'";

                 if (querylite.exec(sqlStr1)==true) //Executes the query
                 {
                     while (querylite.next()) //While u have records
                  {
                         mycode1 = querylite.value(querylite.record().indexOf("ReceiptNo")).toString();
                         ui->label_20->setText(mycode1);

                         mycode1 = querylite.value(querylite.record().indexOf("PayDate")).toString();
                         ui->label_19->setText(mycode1);

                         mycode1 = querylite.value(querylite.record().indexOf("VisitDate")).toString();
                         ui->label_22->setText(mycode1);
                    }
                 }
        }
    }
}



void Cashier::on_pushButton_clicked()
{
    Dialog conn;
    QString pid;
    pid=ui->txt_pid->text();

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    int ck = QDateTime::currentMSecsSinceEpoch();
    QString sk = "R"+QString::number(ck);

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into cashier (PatientID,ReceiptNo,PayDate,VisitDate) "
                "values('"+pid+"','"+sk+"','"+dateTimeString+"','"+dateTimeString+"')");
    qry.exec();


    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(conn.mydb);

    qry1->prepare("select * from laboratory where PatientID='"+pid+"' and Status=:sub");
    qry.bindValue(":sub","0");
    qry1->exec();
    model->setQuery(*qry1);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());


    if(conn.connOpen())
 {
        QSqlQuery querylite;
         QString sqlStr;
         QString mycode;

         sqlStr = "select * from patient where PatientID='"+pid+"'";

         if (querylite.exec(sqlStr)==true) //Executes the query
         {
             while (querylite.next()) //While u have records
             {
                 mycode = querylite.value(querylite.record().indexOf("PatientName")).toString();  //Get the data from the query
                  ui->label_18->setText(mycode);  //set the data to the label

                  mycode = querylite.value(querylite.record().indexOf("SurName")).toString();  //Get the data from the query
                   ui->label_2->setText(mycode);  //set the data to the label

                 mycode = querylite.value(querylite.record().indexOf("PatientID")).toString();
                 ui->label_21->setText(mycode);
             }
         }

         if(conn.connOpen())
         {
             QSqlQuery querylite;
              QString sqlStr1;
              QString mycode1;

                 sqlStr1 = "select * from cashier where PatientID='"+pid+"'";

                 if (querylite.exec(sqlStr1)==true) //Executes the query
                 {
                     while (querylite.next()) //While u have records
                  {
                         mycode1 = querylite.value(querylite.record().indexOf("ReceiptNo")).toString();
                         ui->label_20->setText(mycode1);

                         mycode1 = querylite.value(querylite.record().indexOf("PayDate")).toString();
                         ui->label_19->setText(mycode1);

                         mycode1 = querylite.value(querylite.record().indexOf("VisitDate")).toString();
                         ui->label_22->setText(mycode1);
                    }
                 }
        }
    }
}



