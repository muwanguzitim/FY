#include "pharmacy_newstock.h"
#include "ui_pharmacy_newstock.h"
#include "dialog.h"
#include <QMessageBox>

Pharmacy_newstock::Pharmacy_newstock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pharmacy_newstock)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Pharmacy_newstock::~Pharmacy_newstock()
{
    delete ui;
}


void Pharmacy_newstock::on_pushButton_3_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    {
    QString name;
    name=ui->txt_name_2->text();

    qry->prepare("select * from medicinelist where MedicineName='"+name+"'");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

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

void Pharmacy_newstock::on_pushButton_8_clicked()
{
    Dialog conn;
    QString name,msn,company,qtysupplied,qtyleft,nsd,contact,cost,mid;
    name=ui->txt_name->text();
    msn=ui->txt_msn->text();
    company=ui->txt_company->text();
    qtysupplied=ui->txt_qs->text();
    qtyleft=ui->txt_ql->text();
    nsd=ui->txt_nsd->text();
    contact=ui->txt_contact->text();
    cost=ui->txt_cost->text();
    mid=ui->txt_mid->text();

    if(!contact.toInt()){
         QMessageBox::critical(this,tr("Input validation"),tr("Enter appropriate values"));
    }else
    {

    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    int ck = QDateTime::currentMSecsSinceEpoch();
    QString sk = "M"+QString::number(ck);

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("dd-MM-yyyy hh:mm:ss");

    qry.prepare("insert into medicinelist (MedicineName,MedicineID,Cost,MedicineSerialNo,Company,QuantitySupplied,QuantityLeft,SupplyDate,NextSupplyDate,Contact) "
                "values('"+name+"','"+sk+"','"+cost+"','"+msn+"','"+company+"','"+qtysupplied+"','"+qtyleft+"','"+dateTimeString+"','"+nsd+"','"+contact+"')");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Success"),tr("Added to inventory"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}
}
void Pharmacy_newstock::on_pushButton_clicked()
{
    Dialog conn;
    QString name,msn,company,qtysupplied,qtyleft,nsd,contact,cost,mid;
    name=ui->txt_name->text();
    msn=ui->txt_msn->text();
    company=ui->txt_company->text();
    qtysupplied=ui->txt_qs->text();
    qtyleft=ui->txt_ql->text();
    nsd=ui->txt_nsd->text();
    contact=ui->txt_contact->text();
    cost=ui->txt_cost->text();
    mid=ui->txt_mid->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("UPDATE medicinelist SET MedicineName=:ad,Cost=:d,MedicineSerialNo=:msn,Company=:co,QuantitySupplied=:qs,QuantityLeft=:ql,NextSupplyDate=:nsd,Contact=:c WHERE MedicineID=:mid");
    qry.bindValue(":mid", mid);
    qry.bindValue(":ad", name);
    qry.bindValue(":d", cost);
    qry.bindValue(":msn", msn);
    qry.bindValue(":co", company);
    qry.bindValue(":qs", qtysupplied);
    qry.bindValue(":ql", qtyleft);
    qry.bindValue(":nsd", nsd);
    qry.bindValue(":c", contact);

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


void Pharmacy_newstock::on_pushButton_2_clicked()
{
    Dialog conn;
    QString name,msn,company,qtysupplied,qtyleft,nsd,contact,cost,mid;
    name=ui->txt_name->text();
    msn=ui->txt_msn->text();
    company=ui->txt_company->text();
    qtysupplied=ui->txt_qs->text();
    qtyleft=ui->txt_ql->text();
    nsd=ui->txt_nsd->text();
    contact=ui->txt_contact->text();
    cost=ui->txt_cost->text();
    mid=ui->txt_mid->text();

    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("Delete from medicinelist where MedicineID='"+mid+"'");

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


void Pharmacy_newstock::on_tableView_activated(const QModelIndex &index)
{
    QString mid=ui->tableView->model()->data(index).toString();

    Dialog conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from medicinelist where MedicineID='"+mid+"'");

    if(qry.exec())
    {
        while (qry.next())
        {
            ui->txt_mid->setText(qry.value(0).toString());
            ui->txt_name->setText(qry.value(1).toString());
            ui->txt_cost->setText(qry.value(2).toString());
            ui->txt_msn->setText(qry.value(3).toString());
            ui->txt_company->setText(qry.value(4).toString());
            ui->txt_qs->setText(qry.value(5).toString());
            ui->txt_ql->setText(qry.value(6).toString());
            ui->txt_nsd->setText(qry.value(7).toString());
            ui->txt_contact->setText(qry.value(9).toString());
        }
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}
