#include "prescription_admin.h"
#include "ui_prescription_admin.h"
#include "dialog.h"
#include "addprescription_admin.h"


Prescription_Admin::Prescription_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prescription_Admin)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Prescription_Admin::~Prescription_Admin()
{
    delete ui;
}

void Prescription_Admin::on_pushButton_2_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from prescription_admin");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
}

void Prescription_Admin::on_pushButton_clicked()
{
    AddPrescription_Admin myAP;
    myAP.setModal(true);
    myAP.exec();
}
