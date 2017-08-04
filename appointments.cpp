#include "appointments.h"
#include "ui_appointments.h"
#include <QMessageBox>
#include "schedule.h"

Appointments::Appointments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointments)
{
    ui->setupUi(this);

    Dialog conn;
    if(!conn.connOpen())
        ui->label_7->setText("x");
    else
        ui->label_7->setText("+");

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Appointments::~Appointments()
{
    delete ui;
}



void Appointments::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from appointment");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
}

void Appointments::on_pushButton_4_clicked()
{
    this->hide();
    Schedule myS;
    myS.setModal(true);
    myS.exec();
}
