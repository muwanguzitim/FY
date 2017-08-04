#include "laboratory.h"
#include "ui_laboratory.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTime>

Laboratory::Laboratory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Laboratory)
{
    ui->setupUi(this);

    Dialog conn;
    if(!conn.connOpen())
        ui->label->setText("x");
    else
        ui->label->setText("+");

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Laboratory::~Laboratory()
{
    delete ui;
}

void Laboratory::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientid;
    patientid=ui->txt_pid->text();

    qry->prepare("select * from laboratory where PatientID='"+patientid+"' and Status=:sub");
    qry->bindValue(":sub","Pending");


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
}


void Laboratory::on_pushButton_2_clicked()
{
    Dialog conn;
    QString result1,testid,WBC,NEU,LYM,MON,RBC,HGB,MCV,MCH,PLT,pid;
    result1=ui->txt_result->toPlainText();
    testid=ui->txt_tid->text();
    pid=ui->txt_pid->text();
    WBC=ui->txt_WBC->text();
    NEU=ui->txt_NEU->text();
    LYM=ui->txt_LYM->text();
    MON=ui->txt_MON->text();
    RBC=ui->txt_RBC->text();
    HGB=ui->txt_HGB->text();
    MCV=ui->txt_MCV->text();
    MCH=ui->txt_MCH->text();
    PLT=ui->txt_PLT->text();


   if(!WBC.toInt()||!NEU.toInt()||!LYM.toInt()||!MON.toInt()||!RBC.toInt()||!HGB.toInt()||!MCV.toInt()||!MCH.toInt()||!PLT.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Blood count values shouldnt be empty and should be numbers "));
    }else

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry,qry1;

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

    qry1.prepare("insert into blood_test (PatientID,Date,WBC,NEU,LYM,MON,RBC,HGB,MCV,MCH,PLT) "
              "values('"+pid+"','"+dateTimeString+"','"+WBC+"','"+NEU+"','"+LYM+"','"+MON+"','"+RBC+"','"+HGB+"','"+MCV+"','"+MCH+"','"+PLT+"')");

    qry.prepare("UPDATE laboratory SET Result=:result1,Status=:status WHERE TestID=:testid");
    qry.bindValue(":result1", result1);
    qry.bindValue(":testid", testid);
    qry.bindValue(":status", "Done");
    if(qry.exec()&qry1.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Added"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());

    }

}

