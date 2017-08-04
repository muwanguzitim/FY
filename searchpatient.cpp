#include "searchpatient.h"
#include "ui_searchpatient.h"
#include "receiptionist.h"
#include <QMessageBox>

SearchPatient::SearchPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchPatient)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->comboBox_speciality->addItem(" ");
}

SearchPatient::~SearchPatient()
{
    delete ui;
}

void SearchPatient::on_pushButton_3_clicked()
{
    this->hide();
    Receiptionist myRec;
    myRec.setModal(true);
    myRec.exec();
}


void SearchPatient::on_pushButton_2_clicked()
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

    qry->prepare("select * from patient where PatientName='"+patientname+"' and SurName='"+lastname+"' and phone='"+phone+"'");

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
                ui->label_9->setText("Fill in missing fields ");

            if(count<1)
                ui->label_9->setText("Fill in *missing fields");
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }

}


void SearchPatient::on_pushButton_6_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select Speciality from doctor_info");

    qry->exec();
    model->setQuery(*qry);
    ui->comboBox_speciality->setModel(model);
}

void SearchPatient::on_comboBox_speciality_currentIndexChanged(const QString &arg1)
{
    QString spec=ui->comboBox_speciality->currentText();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select speciality from doctor_info where speciality='"+spec+"'");

    if(qry.exec())

    {
        while (qry.next())
        {
            ui->txt_spec->setText(qry.value(0).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void SearchPatient::on_pushButton_clicked()
{
    Dialog conn;
    QString PatientID,fn,ln,speciality;
    PatientID=ui->txt_id->text();
    fn=ui->txt_pn->text();
    ln=ui->txt_ln->text();
    speciality=ui->txt_spec->text();

    if(speciality.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Doctor cannot contain numeric values"));
    }else if(!PatientID.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("PatientID should be numbers only"));
    }else{

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into queue (PatientID,PatientName,LastName,Speciality) "
                "values('"+PatientID+"','"+fn+"','"+ln+"','"+speciality+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Added to queue"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

}

void SearchPatient::on_tableView_activated(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(index).toString();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select PatientID from patient where PatientID='"+id+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
            ui->txt_id->setText(qry.value(0).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}
