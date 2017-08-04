#include "viewusers_admin.h"
#include "ui_viewusers_admin.h"
#include "dialog.h"

ViewUsers_Admin::ViewUsers_Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewUsers_Admin)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/tim/Downloads/hms/Images/hms.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

ViewUsers_Admin::~ViewUsers_Admin()
{
    delete ui;
}



void ViewUsers_Admin::on_pushButton_clicked()
{
    Dialog conn;
    QSqlQueryModel* model = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from login");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    conn.connClose();
    qDebug()<<(model->rowCount());
}
