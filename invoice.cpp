#include "invoice.h"
#include "ui_invoice.h"
#include "dialog.h"

Invoice::Invoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invoice)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Invoice::~Invoice()
{
    delete ui;
}

void Invoice::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString pid;
    pid=ui->txt_pid->text();


    qry->prepare("select * from pharmacy where PatientID='"+pid+"'");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->label->setText("   ");

    if(qry->exec())
        {
            int count=0;
            while(qry->next())
            {
                count++;
            }

            if(count==1)
             {
                ui->label->setText(" ");
            }
                if(count>1)
                ui->label->setText(" ");

            if(count<1)
                ui->label->setText("Fill in *missing fields");
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }
    }


void Invoice::on_pushButton_2_clicked()
{

    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry1 = new QSqlQuery(conn.mydb);

    {
    QString pid;
    pid=ui->txt_pid->text();


    qry1->prepare("select * from laboratory where PatientID='"+pid+"'");

    qry1->exec();
    model->setQuery(*qry1);
    ui->tableView_2->setModel(model);
    ui->label->setText("   ");

    if(qry1->exec())
        {
            int count=0;
            while(qry1->next())
            {
                count++;
            }

            if(count==1)
             {
                ui->label->setText(" ");
            }
                if(count>1)
                ui->label->setText(" ");

            if(count<1)
                ui->label->setText("Fill in *missing fields");
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }
}
