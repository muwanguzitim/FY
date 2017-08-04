#include "readyresults.h"
#include "ui_readyresults.h"
#include "dialog.h"

ReadyResults::ReadyResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReadyResults)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

ReadyResults::~ReadyResults()
{
    delete ui;
}

void ReadyResults::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientid;
    patientid=ui->lineEdit_2->text();

    qry->prepare("select * from laboratory where PatientID='"+patientid+"' and Status=:done");
    qry->bindValue(":done", "done");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->label_fill->setText("   ");


    if(qry->exec())
        {
            int count=0;
            while(qry->next())
            {
                count++;
            }

            if(count==1)
             {
                ui->label_fill->setText(" ");
            }
                if(count>1)
                ui->label_fill->setText(" ");

            if(count<1)
                ui->label_fill->setText("Fill in *missing fields");
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }


   if(conn.connOpen())
     {
        QSqlQuery querylite;
         QString sqlStr;
         QString mycode;

         QString patientid;
         patientid=ui->lineEdit_2->text();

         sqlStr = "select * from blood_test where PatientID='"+patientid+"'";

         if (querylite.exec(sqlStr)==true) //Executes the query
         {
             while (querylite.next()) //While u have records
             {
                 mycode = querylite.value(querylite.record().indexOf("WBC")).toString();  //Get the data from the query
                  ui->label_3->setText(mycode);  //set the data to the label

                 mycode = querylite.value(querylite.record().indexOf("NEU%")).toString();
                 ui->label_4->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("LYM%")).toString();
                 ui->label_5->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("MON")).toString();
                 ui->label_6->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("RBC")).toString();
                 ui->label_7->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("HGB")).toString();
                 ui->label_8->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("MCV")).toString();
                 ui->label_9->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("MCH")).toString();
                 ui->label_10->setText(mycode);

                 mycode = querylite.value(querylite.record().indexOf("PLT")).toString();
                 ui->label_11->setText(mycode);

             }
        }
    }
}
