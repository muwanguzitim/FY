#include "triage.h"
#include "ui_triage.h"
#include <QMessageBox>
#include <QTime>

Triage::Triage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Triage)
{
    ui->setupUi(this);


    Dialog conn;
    if(!conn.connOpen())
        ui->label_7->setText("x");
    else
        ui->label_7->setText("+");

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Triage::~Triage()
{
    delete ui;
}

void Triage::on_pushButton_2_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString patientid;
    patientid=ui->txt_pid->text();

    qry->prepare("select * from patient where PatientID='"+patientid+"'");

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
                ui->label_fill->setText("  ");
            }
                if(count>1)
                ui->label_fill->setText("Fill in missing fields ");

            if(count<1)
                ui->label_fill->setText("Fill in *missing fields");
    }

    conn.connClose();
    qDebug()<<(model->rowCount());
    }

}

void Triage::on_pushButton_clicked()
{
    Dialog conn;
    QString patientID,weight,temp,height,pulse,bp,hc,bsa,rr,os,hr,bmi;
    patientID=ui->txt_pid->text();
    weight=ui->txt_weight->text();
    temp=ui->txt_temp->text();
    height=ui->txt_height->text();
    pulse=ui->txt_pulse->text();
    bp=ui->txt_bp->text();
    hc=ui->txt_hc->text();
    bsa=ui->txt_bsa->text();
    rr=ui->txt_rr->text();
    os=ui->txt_os->text();
    hr=ui->txt_hr->text();
    bmi=ui->txt_bmi->text();

    if(!patientID.toInt()||!weight.toInt()||!temp.toInt()||!height.toInt()||!pulse.toInt()||!bp.toInt()||!hc.toInt()||!bsa.toInt()||!rr.toInt()||!os.toInt()||!hr.toInt()||!bmi.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Enter appropriate values"));
    }else
    {

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into triage (PatientID,Date,weight,temp,height,pulse,bp,hc,bsa,rr,os,hr,bmi) "
                "values('"+patientID+"','"+dateTimeString+"','"+weight+"','"+temp+"','"+height+"','"+pulse+"','"+bp+"','"+hc+"','"+bsa+"','"+rr+"','"+os+"','"+hr+"','"+bmi+"')");

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

